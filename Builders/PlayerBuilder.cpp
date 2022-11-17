/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** PlayerBuilder
*/

#include "PlayerBuilder.hpp"

PlayerBuilder::PlayerBuilder()
{
}

PlayerBuilder::~PlayerBuilder()
{
}

void PlayerBuilder::reset(position_t position) {
    // _entity = new Entity(position);
    _entity = Entity(position);
    _components.clear();
}

void PlayerBuilder::setModel(int keyUp, int keyDown, int keyLeft, int keyRight, int keyBomb) {
    std::shared_ptr<Components::Object> model(new Components::Object(_entity.getPosition3D(), keyUp, keyDown, keyLeft, keyRight, keyBomb));

    _components.push_back(model);
}

void PlayerBuilder::setMovement() {
    std::shared_ptr<Components::Movements> mvt(new Components::Movements());

    _components.push_back(mvt);
}

void PlayerBuilder::setCollision() {
    // std::shared_ptr<Components::Collision> collision(new Components::Collision());
    std::shared_ptr<Components::Collision> collision = std::make_shared<Components::Collision>();
    _components.push_back(collision);
}

void PlayerBuilder::setBomb() {
    std::shared_ptr<Components::Bomb> bomb(new Components::Bomb());

    _components.push_back(bomb);
}

void PlayerBuilder::setIA(int id) {
    std::shared_ptr<Components::Ia> ia(new Components::Ia(id));

    _components.push_back(ia);
}

void PlayerBuilder::addComps() {
    _entity.addComponents(_components);
}

Entity &PlayerBuilder::getEntity() {
    return _entity;
}
