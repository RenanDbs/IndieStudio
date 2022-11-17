/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Collision
*/

#ifndef COLLISION_HPP_
#define COLLISION_HPP_

#include "IComponent.hpp"
#include "Collision.hpp"
#include "Shapes.hpp"
#include "Object.hpp"
#include <memory>

namespace Components {
    class Collision : public IComponent {
        public:
            Collision() {_componentType = COLLISION;};
            void getModelBounding(Model model);
            bool checkCollision(Texture2D cubicMap, Vector3 mapPos, Vector3 playerPos, Color *color);
            bool checkBoxCollision(const std::vector<std::shared_ptr<Components::Shapes>> box, size_t nbbox, Vector3 playerPos);

        private:
    };
}

#endif /* !COLLISION_HPP_ */
