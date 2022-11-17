/*
** EPITECH PROJECT, 2022
** Movements.hpp
** File description:
** Movements
*/

#ifndef MOVEMENTS_HPP_
#define MOVEMENTS_HPP_

#include "IComponent.hpp"
#include "Collision.hpp"
#include "Shapes.hpp"
#include "Object.hpp"

namespace Components {
    class Movements : public IComponent{
        public:
            Movements() {_componentType = MOVEMENTS;};
            void getMovementShapes(std::shared_ptr<Components::Shapes> player, std::shared_ptr<Components::Collision> collision, std::shared_ptr<Components::Shapes> map);
            void getMovementObject(std::shared_ptr<Components::Object> player, std::shared_ptr<Components::Collision> collision, std::shared_ptr<Components::Shapes> map, const std::vector<std::shared_ptr<Components::Shapes>> box, size_t nbbox);
            void getMovementObjectIA(std::shared_ptr<Components::Object> player, std::shared_ptr<Components::Collision> collision, std::shared_ptr<Components::Shapes> map, std::vector<std::shared_ptr<Components::Shapes>> box, size_t nbbox, int direction);
    };
}

#endif /* !MOVEMENTS_HPP_ */
