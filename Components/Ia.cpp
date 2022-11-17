/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Entity
*/

#include "../Entity/Entity.hpp"
#include <math.h>
#include <algorithm>

Components::Ia::Ia(int id): _id(id)
{
    _componentType = ComponentTypes::IA;
}

Components::Ia::~Ia()
{
}

int Components::Ia::getId() {
    return _id;
}


float Components::Ia::getDistance()
{
    return _distance;
}

void Components::Ia::setDistance(float distance)
{
    _distance = distance;
}

direction Components::Ia::getDirection()
{
    return _direction;
}

void Components::Ia::setDirection(direction dir)
{
    _direction = dir;
}


float Components::Ia::distanceBetweenTwoPoints(Vector2 point1, Vector2 point2)
{
    return (float)sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));
}

void Components::Ia::addDodgingBomb(std::shared_ptr<Components::Bomb> bomb)
{
    _coorDodgingBomb.push_back(bomb);
}

std::vector<std::shared_ptr<Components::Bomb>> Components::Ia::getDodgingBomb(void)
{
    return _coorDodgingBomb;
}
bool Components::Ia::isDodgingBomb(void)
{
    return _isDodgingBomb;
}

void Components::Ia::dodgingBomb(bool state)
{
    _isDodgingBomb = state;
}

bool Components::Ia::isBombOnPath(Entity &player, std::vector<std::shared_ptr<Components::Bomb>> bombVect)
{
    // for (int i = 0; i < bombVect.size(); i++) {
        // std::cout << bombVect.size() << std::endl;
    for (const auto &i : bombVect) {
        if (std::find(player.getIAComp()->getDodgingBomb().begin(), player.getIAComp()->getDodgingBomb().end(), i) == bombVect.end()) { //si la distance entre la bombe et le joueur est plus petite que 3 et si on a au moins axe similaire que la bombe
            
            addDodgingBomb(i);
            //si on est sur la meme coor x ou z 
        }
        if (distanceBetweenTwoPoints(player.getObjectComp()->getPos2D(), Vector2{i->getPosition().x, i->getPosition().z}) <= 4 &&
            player.getObjectComp()->getPos2D().x - i->getPosition().x > -0.5 && player.getObjectComp()->getPos2D().x - i->getPosition().x < 0.5) {
            return true;
        }
        if (distanceBetweenTwoPoints(player.getObjectComp()->getPos2D(), Vector2{i->getPosition().x, i->getPosition().z}) <= 4 &&
            player.getObjectComp()->getPos2D().y - i->getPosition().z > -0.5 && player.getObjectComp()->getPos2D().y - i->getPosition().z < 0.5) { // on met y parce que c'est une pos 2D (donc ici y == z)
            return true;
        }
    }
    return false;
}

bool Components::Ia::checkCollision(Entity &entity, Entity &box, Entity &map) {
    Vector3 pos = entity.getObjectComp()->getPos3D();

    switch (_direction) {
        case LEFT:
            return (entity.getCollisionComp()->checkBoxCollision(box.getBoxVec(), box.getnbBox(), {pos.x - 0.05f, 0.5f, pos.z}) || entity.getCollisionComp()->checkCollision(map.getShapesComp()->getCubicmap(), map.getPosition3D(), entity.getPosition3D(), map.getShapesComp()->getMapPixels()));
        case RIGHT:
            return (entity.getCollisionComp()->checkBoxCollision(box.getBoxVec(), box.getnbBox(), {pos.x + 0.05f, 0.5f, pos.z}) || entity.getCollisionComp()->checkCollision(map.getShapesComp()->getCubicmap(), map.getPosition3D(), entity.getPosition3D(), map.getShapesComp()->getMapPixels()));
        case UP:
            return (entity.getCollisionComp()->checkBoxCollision(box.getBoxVec(), box.getnbBox(), {pos.x, 0.5f, pos.z - 0.05f}) || entity.getCollisionComp()->checkCollision(map.getShapesComp()->getCubicmap(), map.getPosition3D(), entity.getPosition3D(), map.getShapesComp()->getMapPixels()));
        case DOWN:
            return (entity.getCollisionComp()->checkBoxCollision(box.getBoxVec(), box.getnbBox(), {pos.x, 0.5f, pos.z + 0.05f}) || entity.getCollisionComp()->checkCollision(map.getShapesComp()->getCubicmap(), map.getPosition3D(), entity.getPosition3D(), map.getShapesComp()->getMapPixels()));
        case NONE:
            break;
    }
    return false;
}

enum direction Components::Ia::getNextMove(Entity &entity, Entity &map, Entity &box, std::vector<Entity> &players, std::vector<std::shared_ptr<Components::Bomb>> bombVect)
{
    bool bombPosed = false;
    std::vector<std::shared_ptr<Components::Object>> playersObjects;
    for (int i = 0; i < 4; i++)
        playersObjects.push_back(players[i].getObjectComp());
    //diff entre les deux vec
    if (checkCollision(entity, box, map)) {
        _direction = direction::POSE_BOMB;
        bombPosed = true;
        // entity.getBombComp()->spawnBomb(entity.getBombComp()->setBomb(entity.getObjectComp()), playersObjects, box.getBoxVec(), box.getnbBox(), bonus, playerObjectComp->getPower(), bombvector, menu, draw, sphere)
    }
    for (int i = 0; i < bombVect.size(); i++) {
        for (int j = 0; j < entity.getIAComp()->getDodgingBomb().size(); j++) {
            // std::cout << "dodging bomb size = " << entity.getIAComp()->getDodgingBomb().size() << std::endl;
            //si les coor de la->getDodgingBomb[j] n'est pas dans bomb[i]
                //on remove la->getDodgingBomb[j]
            if (entity.getIAComp()->getDodgingBomb()[j]->getPosition().x == bombVect[i]->getPosition().x && entity.getIAComp()->getDodgingBomb()[j]->getPosition().z == bombVect[i]->getPosition().z) {
                //entity.getIAComp()->getDodgingBomb().erase(entity.getIAComp()->getDodgingBomb().begin() + j);
            }
        }
    }
    dodgingBomb(getDodgingBomb().size());
    if (entity.getIAComp()->isBombOnPath(entity, bombVect) == true) { //si on va en direction d'une bombe :
        //on bouge : (on fait un L on ? on fait demi tour ?) 
        for (int i = 0; i < bombVect.size(); i++) {
            //on regarde les coor de la bombe et on va dans le sens inverse
            if (entity.getObjectComp()->getPos2D().x - bombVect[i]->getPosition().x > -0.5 && entity.getObjectComp()->getPos2D().x - bombVect[i]->getPosition().x < 0.5) {
                if (entity.getObjectComp()->getPos2D().x - bombVect[i]->getPosition().x <= 0)
                    entity.getIAComp()->setDirection(UP);
                else 
                    entity.getIAComp()->setDirection(DOWN);
                while (checkCollision(entity, box, map)) {
                    if (_direction == POSE_BOMB)
                        _direction = LEFT;
                    return ((direction)(_direction + 1));
                }
            }
            if (entity.getObjectComp()->getPos2D().y - bombVect[i]->getPosition().z > -0.5 && entity.getObjectComp()->getPos2D().y - bombVect[i]->getPosition().z < 0.5){ // on met y parce que c'est une pos 2D (donc ici y == z)
                if (entity.getObjectComp()->getPos2D().y - bombVect[i]->getPosition().y <= 0) {
                    entity.getIAComp()->setDirection(LEFT);
                }
                else { 
                    entity.getIAComp()->setDirection(RIGHT);
                }
            }
    }
    } else  if (!bombPosed) {
        float distMin = 1000;
        //  = distanceBetweenTwoPoints(entity.getObjectComp()->getPos2D(), players[0].getObjectComp()->getPos2D());
        int nearestPlayer = 0;
        for (int j = 0; j <= 3; j++) {
            if (j != entity.getIAComp()->getId() && (distMin > sqrt(pow((entity.getObjectComp()->getPos2D().x - players[j].getObjectComp()->getPos2D().x), 2) + pow((entity.getObjectComp()->getPos2D().y - players[j].getObjectComp()->getPos2D().y), 2)))) {
                distMin = (float)sqrt(pow((entity.getObjectComp()->getPos2D().x - players[j].getObjectComp()->getPos2D().x), 2) + pow((entity.getObjectComp()->getPos2D().y - players[j].getObjectComp()->getPos2D().y), 2));
                nearestPlayer = j;
            }
        }
        float diffX = entity.getObjectComp()->getPos2D().x - players[nearestPlayer].getObjectComp()->getPos2D().x;
        float diffY = entity.getObjectComp()->getPos2D().y - players[nearestPlayer].getObjectComp()->getPos2D().y;

        if (abs(diffX) > abs(diffY) && !bombPosed) {
            if (diffX > 0)
                entity.getIAComp()->setDirection(LEFT);
            else
                entity.getIAComp()->setDirection(RIGHT);
        } else {
            if (diffY > 0)
                entity.getIAComp()->setDirection(UP);
            else
                entity.getIAComp()->setDirection(DOWN);
        }
    }
    return entity.getIAComp()->getDirection();

}

enum direction Components::Ia::moveIA(std::vector<Entity> &players, int i, Entity &map, Entity &box, const std::vector<std::shared_ptr<Components::Shapes>> boxVec, std::vector<std::shared_ptr<Components::Bomb>> bombVect)
{
    std::vector<std::shared_ptr<Components::Shapes>> boxes = box.getBoxVec();
    // std::cout << "distance parcourue = " << players[i].getIAComp()->getDistance() << std::endl;
    // auto playerIaComp = players[i].getIAComp();
    // std::cout << players[i].getIAComp()->getDistance() << std::endl;
    // std::cout << "x: " << players[i].getObjectComp()->getPos2D().x <<  "; y: " << players[i].getObjectComp()->getPos2D().y << std::endl;
    if (players[i].getIAComp()->getDistance() <= 1) { //si on ne s'est pas déplacé de 1
        players[i].getIAComp()->setDirection(getNextMove(players[i], map, box, players, bombVect)); //on prends une nouvelle direction
        players[i].getIAComp()->setDistance(players[i].getIAComp()->getDistance() + players[i].getObjectComp()->getSpeed()); // on set la nouvelle distance parcourue
    } else {
        players[i].getIAComp()->setDirection(getNextMove(players[i], map, box, players, bombVect)); //on prends une nouvelle direction
        players[i].getIAComp()->setDistance(0);
    }
    players[i].getMovementComp()->getMovementObjectIA(players[i].getObjectComp(), players[i].getCollisionComp(), map.getShapesComp(), boxVec, box.getnbBox(), players[i].getIAComp()->getDirection());
    return _direction;
    // return direction::POSE_BOMB;
}



/*
Move {
    checker les collisions
    checker si on est proche d'une bombe
        (piste d'amélioration en gardant en mémoire les spécificités des
        bombes ennemies)
}
*/

/*
var dist1 = distance avec le joueur le plus proche;
ver distbonus = distance avec le bonus le plus proche;
if (joueur sur la traj d'une bombe)
    on bouge dans un autre axe
else if (dist1 < 5)
    poser une bombe pour tuer les ennemis
else if (distbonus < 4)
    prendre les bonus
else
    se deplacer
    poser une bombe pour peter les murs
*/
