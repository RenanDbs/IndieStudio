/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "IComponent.hpp"

namespace Components {
    class Camera : public IComponent {
        public:
            Camera() = default;
            Camera(Vector3 cameraLook, Vector3 cameraVec, Vector3 cameraPosition);
            ~Camera();
            Camera3D getCamera() const;
        private:
            Camera3D _camera;
    };
}

#endif /* !CAMERA_HPP_ */
