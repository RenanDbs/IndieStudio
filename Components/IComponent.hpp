/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Entity
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <vector>
#include <raylib.h>
#include <string>
#include <raymath.h> 
#include <iostream>

enum ComponentTypes {
    CAMERA,
    HEALTH,
    MOVEMENTS,
    RENDER,
    SPHERE,
    SQUARE,
    OBJECT,
    TEXT,
    COLLISION,
    BOMB,
    IA,
};

namespace Components {
    class IComponent {
        public:
            enum ComponentTypes getComponentType() const {
                return _componentType;
            };
        protected:
            enum ComponentTypes _componentType;
    };
}

#endif /* ICOMPONENT_HPP_ */
