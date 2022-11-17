/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** PlayerBuilder
*/

#ifndef PLAYERBUILDER_HPP_
#define PLAYERBUILDER_HPP_

#include "./IEntityBuilder.hpp"

class PlayerBuilder : public IEntityBuilder {
    public:
        PlayerBuilder();
        ~PlayerBuilder();
        void reset(position_t position);
        void setModel(int keyUp, int keyDown, int keyLeft, int keyRight, int keyBomb);
        void setMovement();
        void setCollision();
        void setBomb();
        void setIA(int id);
        void addComps();
        Entity &getEntity();

    private:
        Entity _entity;
        std::vector<std::shared_ptr<Components::IComponent>> _components;
};

#endif /* !PLAYERBUILDER_HPP_ */
