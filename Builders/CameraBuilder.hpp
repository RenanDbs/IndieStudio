/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** CameraBuilder
*/

#ifndef CAMERABUILDER_HPP_
#define CAMERABUILDER_HPP_

#include "IEntityBuilder.hpp"

class CameraBuilder : public IEntityBuilder {
    public:
        CameraBuilder();
        ~CameraBuilder();
        void reset(position_t position);
        void setCameraComp(position_t look, position_t vec);
        void addComps();
        Entity &getEntity();

    private:
        Entity _entity;
        std::vector<std::shared_ptr<Components::IComponent>> _components;
};

#endif /* !CAMERABUILDER_HPP_ */
