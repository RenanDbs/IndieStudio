/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Camera
*/

#include "Camera.hpp"

Components::Camera::Camera(Vector3 cameraLook, Vector3 cameraVec, Vector3 cameraPosition)
{
    _componentType = ComponentTypes::CAMERA;
    _camera.target = cameraLook;
    _camera.up = cameraVec;
    _camera.position = cameraPosition;
    _camera.fovy = 50;
    _camera.projection = CAMERA_PERSPECTIVE;
}

Components::Camera::~Camera() {}

Camera3D Components::Camera::getCamera() const {
    return _camera;
}
