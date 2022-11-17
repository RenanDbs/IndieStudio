/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** MapBuilder
*/

#ifndef MAPBUILDER_HPP_
#define MAPBUILDER_HPP_

#include "IEntityBuilder.hpp"

class MapBuilder : public IEntityBuilder {
    public:
        MapBuilder();
        ~MapBuilder();
        void reset(position_t position);
        void setSquareComp(float width, float height, float length, Color color);
        void setCollisionComp();
        void addComps();
        Entity &getEntity();

    private:
        Entity _entity;
        std::vector<std::shared_ptr<Components::IComponent>> _components;
};

#endif /* !MAPBUILDER_HPP_ */
