/*
** EPITECH PROJECT, 2022
** bomb.cpp
** File description:
** Bomb
*/

#include "Bomb.hpp"
// #include "../Entity/Entity.hpp"

Components::Bomb::Bomb()
{
    _componentType = ComponentTypes::BOMB;
    _state = 0;
    _hitP1 = 0;
    _hitP2 = 0;
    _hitP3 = 0;
    _hitP4 = 0;
}

void Components::Bomb::setTextBomb()
{
    _modelBomb = LoadModel("Texture/bomb/untitled.gltf");
    _modelProj = LoadModel("Texture/Explosion/explode.gltf");
}

void Components::Bomb::setPosition(Vector3 position)
{
    _tmp = position;
}

Vector3 Components::Bomb::getPosition() const
{
    return (_tmp);
}

Vector3 Components::Bomb::setBomb(std::shared_ptr<Components::Object> player)
{
    Vector3 pos = {0.0f, 0.0f, 0.0f};

    if (IsKeyDown(player->getBomb()))
        _poseBomb = true;
    if (player->getMatrix().m2 / DEG2RAD >= 24 && player->getMatrix().m2 / DEG2RAD <= 25) {
        pos = {player->getPositionX(), 0.5f, player->getPositionZ()};
    }
    if (player->getMatrix().m2 / DEG2RAD >= -52 && player->getMatrix().m2 / DEG2RAD <= -51) {
        pos = {player->getPositionX(), 0.5f, player->getPositionZ()};
    }
    if (player->getMatrix().m2 / DEG2RAD >= -20 && player->getMatrix().m2 / DEG2RAD <= -19) {
        pos = {player->getPositionX(), 0.5f, player->getPositionZ()};
    }
    if (player->getMatrix().m2 / DEG2RAD >= 55 && player->getMatrix().m2 / DEG2RAD <= 58) {
        pos = {player->getPositionX(), 0.5f, player->getPositionZ()};
    }

    if (_poseBomb){
        _poseBomb = false;
        return pos;
    }
    return {0.0f, 0.0f, 0.0f};
}

void Components::Bomb::setPoseBomb(bool poseBomb) {
    _poseBomb = poseBomb;
}

std::vector<std::shared_ptr<Components::Shapes>> Components::Bomb::spawnBomb(Vector3 pos, std::vector<std::shared_ptr<Components::Object>> objectComps, std::vector<std::shared_ptr<Components::Shapes>> box, size_t nbrBox, std::vector<std::shared_ptr<Components::Shapes>> bonus, float power, std::vector<std::shared_ptr<Components::Bomb>> &bombVector, Menu &menu, Draw &draw, Sphere &sphere)
{
    std::cout << "pos.x: " << pos.x << std::endl;
    if (_state == 0 && pos.x != 0.0f) {
        _tmp = pos;
        float dec = (_tmp.x - int(_tmp.x));
        _tmp.x = roundf(_tmp.x);
        if (abs(dec) < 0.5)
            _tmp.x -= 0.5;
        else if (abs(dec) > 0.5)
            _tmp.x += 0.5;
        else
            _tmp.x = pos.x;
        _tmp.z = roundf(_tmp.z);
        _time = GetTime();
        _state = 1;
        std::shared_ptr<Components::Bomb> bomb(new Components::Bomb);
        bomb->setPosition(_tmp);
        bombVector.push_back(bomb);
        menu.PlayBoom();
        std::cout << "bomb added to vector" << std::endl;
    }
    std::cout << "state: " << _state << std::endl;
    std::cout << "time: " << _time << std::endl;
    if (_time + 3 > GetTime() && _state == 1)
        draw.MyDrawModel(_modelBomb, _tmp, 0.4f, RAYWHITE);
    if (_time + 3 < GetTime() && _state == 1) {
        for (float i = 0; i < power ; i += 0.5f) {
            draw.MyDrawModel(_modelProj, {_tmp.x + i, _tmp.y, _tmp.z}, 0.3f, RAYWHITE);
            draw.MyDrawModel(_modelProj, {_tmp.x - i, _tmp.y, _tmp.z}, 0.3f, RAYWHITE);
            draw.MyDrawModel(_modelProj, {_tmp.x, _tmp.y, _tmp.z + i}, 0.3f, RAYWHITE);
            draw.MyDrawModel(_modelProj, {_tmp.x, _tmp.y, _tmp.z - i}, 0.3f, RAYWHITE);

            for (size_t j = 0; j < nbrBox; j++) {
                if ((sphere.checkCollision(box[j]->getPosition(), 0.45f,{_tmp.x + i, _tmp.y, _tmp.z}, 0.45f) || sphere.checkCollision(box[j]->getPosition(), 0.4f,{_tmp.x - i, _tmp.y, _tmp.z}, 0.5f) ||sphere.checkCollision(box[j]->getPosition(), 0.4f,{_tmp.x, _tmp.y, _tmp.z + i}, 0.5f) || sphere.checkCollision(box[j]->getPosition(), 0.4f,{_tmp.x, _tmp.y, _tmp.z - i}, 0.5f)) && box[j]->isPrintable() == 1) {
                    box[j]->setPrintable(0);
                    if (rand() % 10 == 1) {
                        std::shared_ptr<Components::Shapes> speed(new Components::Shapes(box[j]->getPosition(), 0.5f, 0.5f, 0.5f, RAYWHITE));
                        speed->setPathText("Texture/Skate.png");
                        speed->setBonusType(1);
                        bonus.push_back(speed);
                    } else if (rand() % 10 == 2) {
                        std::shared_ptr<Components::Shapes> range(new Components::Shapes(box[j]->getPosition(), 0.5f, 0.5f, 0.5f, RAYWHITE));
                        range->setPathText("Texture/Fire.png");
                        range->setBonusType(2);
                        bonus.push_back(range);
                    }
                }   
            }
            if (sphere.checkCollision({_tmp.x + i, _tmp.y, _tmp.z}, 0.4f, objectComps[0]->getPos3D(), 0.5f) || sphere.checkCollision({_tmp.x - i, _tmp.y, _tmp.z}, 0.4f, objectComps[0]->getPos3D(), 0.5f) || sphere.checkCollision({_tmp.x, _tmp.y, _tmp.z + i}, 0.4f, objectComps[0]->getPos3D(), 0.5f) || sphere.checkCollision({_tmp.x, _tmp.y, _tmp.z - i}, 0.4f, objectComps[0]->getPos3D(), 0.5f)) {
                if (_hitP1 == 0){
                    objectComps[0]->setHealth(1);
                    _hitP1 = 1;
                }
            }
            if (sphere.checkCollision({_tmp.x + i, _tmp.y, _tmp.z}, 0.4f, objectComps[1]->getPos3D(), 0.5f) || sphere.checkCollision({_tmp.x - i, _tmp.y, _tmp.z}, 0.4f, objectComps[1]->getPos3D(), 0.5f) || sphere.checkCollision({_tmp.x, _tmp.y, _tmp.z + i}, 0.4f, objectComps[1]->getPos3D(), 0.5f) || sphere.checkCollision({_tmp.x, _tmp.y, _tmp.z - i}, 0.4f, objectComps[1]->getPos3D(), 0.5f)) {
                if (_hitP2 == 0){
                    objectComps[1]->setHealth(1);
                    _hitP2 = 1;
                }
            }
            if (sphere.checkCollision({_tmp.x + i, _tmp.y, _tmp.z}, 0.4f, objectComps[2]->getPos3D(), 0.5f) || sphere.checkCollision({_tmp.x - i, _tmp.y, _tmp.z}, 0.4f, objectComps[2]->getPos3D(), 0.5f) || sphere.checkCollision({_tmp.x, _tmp.y, _tmp.z + i}, 0.4f, objectComps[2]->getPos3D(), 0.5f) || sphere.checkCollision({_tmp.x, _tmp.y, _tmp.z - i}, 0.4f, objectComps[2]->getPos3D(), 0.5f)) {
                if (_hitP3 == 0){
                    objectComps[2]->setHealth(1);
                    _hitP3 = 1;
                }
            }
            if (sphere.checkCollision({_tmp.x + i, _tmp.y, _tmp.z}, 0.4f, objectComps[3]->getPos3D(), 0.5f) || sphere.checkCollision({_tmp.x - i, _tmp.y, _tmp.z}, 0.4f, objectComps[3]->getPos3D(), 0.5f) || sphere.checkCollision({_tmp.x, _tmp.y, _tmp.z + i}, 0.4f, objectComps[3]->getPos3D(), 0.5f) || sphere.checkCollision({_tmp.x, _tmp.y, _tmp.z - i}, 0.4f, objectComps[3]->getPos3D(), 0.5f)) {
                if (_hitP4 == 0){
                    objectComps[3]->setHealth(1);
                    _hitP4 = 1;
                }
            }
        }
    }
    if (_time + 4 < GetTime() && _state == 1) {
        std::cout << "len = " << bombVector.size() << std::endl;
        if (bombVector.size() != 0)
            bombVector.erase(bombVector.begin());
        _state = 0;
        _hitP1 = 0;
        _hitP2 = 0;
        _hitP3 = 0;
        _hitP4 = 0;
    }
    return bonus;
}
