/*
** EPITECH PROJECT, 2022
** Model.hpp
** File description:
** Model
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "IComponent.hpp"

namespace Components {
    class Object : public IComponent {
        public:
            Object(Vector3 position, int keyUp, int keyDown, int keyLeft, int keyRight, int keyBomb);
            Object(Vector3 position);
            ~Object();
            void drawObject();
            void setMod(const char* path);
            void setPositionX(float givenPosition);
            void setPositionZ(float givenPosition);
            float getPositionX();
            float getPositionZ();
            int getUp();
            int getDown();
            int getLeft();
            int getRight();
            void setMatrix(int value);
            int getHealth();
            void setHealth(int value);
            int getBomb();
            void setKeys(int keyUp, int keyDown, int keyLeft, int keyRight, int keyBomb);
            Matrix getMatrix();
            Vector2 getPos2D();
            Vector3 getPos3D();
            float getPower();
            void setPower(float power);
            float getSpeed();
            void setSpeed(float speed);
            void setPoseBomb(bool poseBomb);

        private:
            Vector3 _position;
            int _up;
            int _down;
            int _left;
            int _right;
            int _bomb;
            int _health = 1;
            float _power = 2.0f;
            float _speed = 0.05f; 
            Matrix _matrix;
            Model _model;
            Texture2D _texture;
    };
}

#endif /* !OBJECT_HPP_ */
