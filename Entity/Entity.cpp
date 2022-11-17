/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Entity
*/

#include "Entity.hpp"
#include <exception>

Entity::Entity(position_t position) : _position(position) {}

Vector3 Entity::getPosition3D() {
    Vector3 position;
    position.x = _position.x;
    position.y = _position.y;
    position.z = _position.z;

    return position;
}

Entity::~Entity() {
    //for (auto i: _components)
    //    delete i;
}

void Entity::addComponents(std::vector<std::shared_ptr<Components::IComponent>> components) {
    for (auto i: components) {
        _components.push_back(i);
    }
}

void Entity::addBox(std::shared_ptr<Components::Shapes> components) {
        _vecBox.push_back(components);
}

std::vector<std::shared_ptr<Components::Shapes>> Entity::getBoxVec() {
    return _vecBox;
}

std::shared_ptr<Components::Camera> Entity::getCameraComp() const {
// Components::Camera &Entity::getCameraComp() const {
    for (const auto &i: _components) {
        if (i->getComponentType() == CAMERA) 
            return std::reinterpret_pointer_cast<Components::Camera> (i);
    }
    throw "Camera comp not in entity";
}

std::shared_ptr<Components::Shapes> Entity::getShapesComp() {
    for (auto i: _components) {
        if (i->getComponentType() == ComponentTypes::SPHERE || i->getComponentType() == SQUARE)
            return std::reinterpret_pointer_cast<Components::Shapes> (i);
    }
    throw "Shapes comp not in entity";
}

std::shared_ptr<Components::Object> Entity::getObjectComp() {
    for (auto i: _components) {
        if (i->getComponentType() == OBJECT)
            return std::reinterpret_pointer_cast<Components::Object> (i);
    }
    throw "Object comp not in entity";
}

std::shared_ptr<Components::Movements> Entity::getMovementComp() {
    for (auto i: _components) {
        if (i->getComponentType() == MOVEMENTS)
            return std::reinterpret_pointer_cast<Components::Movements> (i);
    }
    throw "Movement comp not in entity";
}

std::shared_ptr<Components::Text> Entity::getTextComp() {
    for (auto i: _components) {
        if (i->getComponentType() == TEXT)
            return std::reinterpret_pointer_cast<Components::Text> (i);
    }
    throw "Text comp not in entity";
}

std::shared_ptr<Components::Collision> Entity::getCollisionComp() {
    for (auto i: _components) {
        if (i->getComponentType() == COLLISION)
            return std::reinterpret_pointer_cast<Components::Collision> (i);
    }
    throw "Collision comp not in entity";
}

std::shared_ptr<Components::Bomb> Entity::getBombComp() {
    for (auto i: _components) {
        if (i->getComponentType() == BOMB)
            return std::reinterpret_pointer_cast<Components::Bomb> (i);
    }
    throw "Bomb comp not in entity";
}

std::shared_ptr<Components::Shapes> Entity::getBoxComp(int i) {
    if (_components[i]->getComponentType() == SQUARE)
        return std::reinterpret_pointer_cast<Components::Shapes> (_components[i]);
    throw "Box comp not in entity";
}

std::shared_ptr<Components::Ia> Entity::getIAComp() {
    for (const auto &i: _components) {
        if (i->getComponentType() == IA)
            return std::reinterpret_pointer_cast<Components::Ia> (i);
    }
    throw "AI comp not in entity";
}

size_t Entity::getnbBox() {
    return _nbBox;
}

void Entity::setNbBox(size_t i) {
    _nbBox = _nbBox + i;
}
