/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** MapBuilder
*/

#include "MapBuilder.hpp"

MapBuilder::MapBuilder()
{
}

MapBuilder::~MapBuilder()
{
}

void MapBuilder::reset(position_t position) {
    // if (_entity)
        // delete _entity;
    // _entity = new Entity(position);
    _entity = Entity(position);
    _components.clear();
}

void MapBuilder::setSquareComp(float width, float height, float length, Color color) {
    std::shared_ptr<Components::IComponent> square(new Components::Shapes(_entity.getPosition3D(), width, height, length, color));
    _components.push_back(square);
}

void MapBuilder::setCollisionComp() {
    std::shared_ptr<Components::IComponent> collisionComp(new Components::Collision());
    _components.push_back(collisionComp); 
}

void MapBuilder::addComps() {
    /*for (auto i : _components) {
        std::cout << "type === " << i->getComponentType() << std::endl;
    }*/
    _entity.addComponents(_components);
}

Entity &MapBuilder::getEntity() {
    return _entity;
}
