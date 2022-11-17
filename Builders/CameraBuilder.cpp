/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** CameraBuilder
*/

#include "CameraBuilder.hpp"

CameraBuilder::CameraBuilder()
{
}

CameraBuilder::~CameraBuilder()
{
}

void CameraBuilder::reset(position_t position) {
    // if (_entity)
        // delete _entity;
    // _entity = new Entity(position);
    _entity = Entity(position);
    _components.clear();
}

void CameraBuilder::setCameraComp(position_t look, position_t vec) {
    Vector3 cameraLook;
    Vector3 cameraVec;

    cameraLook.x = look.x;
    cameraLook.y = look.y;
    cameraLook.z = look.z;
    cameraVec.x = vec.x;
    cameraVec.y = vec.y;
    cameraVec.z = vec.z;
    std::shared_ptr<Components::IComponent> camera(new Components::Camera(cameraLook, cameraVec, _entity.getPosition3D()));
    // camera = Components::Camera(cameraLook, cameraVec, _entity.getPosition3D());
    _components.push_back(camera);
}

void CameraBuilder::addComps() {
    _entity.addComponents(_components);
}

Entity &CameraBuilder::getEntity() {
    return _entity;
}
