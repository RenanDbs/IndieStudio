/*
** EPITECH PROJECT, 2022
** Movements.cpp
** File description:
** Movements
*/

#include "../IndieStudio.hpp"
#include "Movements.hpp"

void Components::Movements::getMovementShapes(std::shared_ptr<Components::Shapes> player, std::shared_ptr<Components::Collision> collision, std::shared_ptr<Components::Shapes> map)
{
    if (IsKeyDown(KEY_LEFT))
        if (!collision->checkCollision(map->getCubicmap(),map->getPosition(), {player->getPositionX() - 0.05f, 0.5f, player->getPositionZ()}, map->getMapPixels()))
            player->setPositionX((float)-0.05);
    if (IsKeyDown(KEY_RIGHT))
        if (!collision->checkCollision(map->getCubicmap(),map->getPosition(), {player->getPositionX() + 0.05f, 0.5f, player->getPositionZ()}, map->getMapPixels()))
            player->setPositionX((float)0.05);
    if (IsKeyDown(KEY_UP))
        if (!collision->checkCollision(map->getCubicmap(),map->getPosition(), {player->getPositionX(), 0.5f, player->getPositionZ() - 0.05f}, map->getMapPixels()))
            player->setPositionZ((float)-0.05);
    if (IsKeyDown(KEY_DOWN))
        if (!collision->checkCollision(map->getCubicmap(),map->getPosition(), {player->getPositionX(), 0.5f, player->getPositionZ() + 0.05f}, map->getMapPixels()))
            player->setPositionZ((float)0.05);
}

void Components::Movements::getMovementObject(std::shared_ptr<Components::Object> player, std::shared_ptr<Components::Collision> collision, std::shared_ptr<Components::Shapes> map, const std::vector<std::shared_ptr<Components::Shapes>> box, size_t nbbox)
{
    if (IsKeyDown(player->getLeft()))
        if (!collision->checkCollision(map->getCubicmap(),map->getPosition(), {player->getPositionX() - 0.05f, 0.5f, player->getPositionZ()}, map->getMapPixels()) && !collision->checkBoxCollision(box, nbbox,{player->getPositionX() - 0.05f, 0.5f, player->getPositionZ()})){
            player->setPositionX(-(player->getSpeed()));
            player->setMatrix(100);
        }
    if (IsKeyDown(player->getRight()))
        if (!collision->checkCollision(map->getCubicmap(),map->getPosition(), {player->getPositionX() + 0.05f, 0.5f, player->getPositionZ()}, map->getMapPixels())  && !collision->checkBoxCollision(box, nbbox, {player->getPositionX() + 0.05f, 0.5f, player->getPositionZ()})) {
            player->setPositionX(player->getSpeed());
            player->setMatrix(295);
        }
    if (IsKeyDown(player->getUp()))
        if (!collision->checkCollision(map->getCubicmap(),map->getPosition(), {player->getPositionX(), 0.5f, player->getPositionZ() - 0.05f}, map->getMapPixels())  && !collision->checkBoxCollision(box, nbbox, {player->getPositionX(), 0.5f, player->getPositionZ() - 0.05f})) {
            player->setPositionZ(-(player->getSpeed()));
            player->setMatrix(200);
        }
    if (IsKeyDown(player->getDown()))
        if (!collision->checkCollision(map->getCubicmap(),map->getPosition(), {player->getPositionX(), 0.5f, player->getPositionZ() + 0.05f}, map->getMapPixels()) && !collision->checkBoxCollision(box, nbbox, {player->getPositionX(), 0.5f, player->getPositionZ() + 0.05f})){
            player->setPositionZ(player->getSpeed());
            player->setMatrix(25);
        }
}

void Components::Movements::getMovementObjectIA(std::shared_ptr<Components::Object> player, std::shared_ptr<Components::Collision> collision, std::shared_ptr<Components::Shapes> map, std::vector<std::shared_ptr<Components::Shapes>> box, size_t nbbox, int direction)
{
    switch (direction) {
        case LEFT: // LEFT
            if (!collision->checkCollision(map->getCubicmap(),map->getPosition(), {player->getPositionX() - 0.05f, 0.5f, player->getPositionZ()}, map->getMapPixels()) && !collision->checkBoxCollision(box, nbbox,{player->getPositionX() - 0.05f, 0.5f, player->getPositionZ()})){
                player->setPositionX(-(player->getSpeed()));
                player->setMatrix(100);
            }
            break;
        case RIGHT: // RIGHT
            if (!collision->checkCollision(map->getCubicmap(),map->getPosition(), {player->getPositionX() + 0.05f, 0.5f, player->getPositionZ()}, map->getMapPixels())  && !collision->checkBoxCollision(box, nbbox, {player->getPositionX() + 0.05f, 0.5f, player->getPositionZ()})) {
                player->setPositionX(player->getSpeed());
                player->setMatrix(295);
            }
            break;
        case UP: // UP
            if (!collision->checkCollision(map->getCubicmap(),map->getPosition(), {player->getPositionX(), 0.5f, player->getPositionZ() - 0.05f}, map->getMapPixels())  && !collision->checkBoxCollision(box, nbbox, {player->getPositionX(), 0.5f, player->getPositionZ() - 0.05f})) {
                player->setPositionZ(-(player->getSpeed()));
                player->setMatrix(200);
            }
            break;
        case DOWN: // DOWN
            if (!collision->checkCollision(map->getCubicmap(),map->getPosition(), {player->getPositionX(), 0.5f, player->getPositionZ() + 0.05f}, map->getMapPixels()) && !collision->checkBoxCollision(box, nbbox, {player->getPositionX(), 0.5f, player->getPositionZ() + 0.05f})){
                player->setPositionZ(player->getSpeed());
                player->setMatrix(25);
            }
            break;
        case NONE:
        default:
            break;
    }
    return;
}
