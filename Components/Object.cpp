/*
** EPITECH PROJECT, 2022
** Object.cpp
** File description:
** Object
*/

#include "Object.hpp"

Components::Object::Object(Vector3 position, int keyUp, int keyDown, int keyLeft, int keyRight, int keyBomb) : _position(position), _up(keyUp), _down(keyDown), _left(keyLeft), _right(keyRight), _bomb(keyBomb)
{
    _componentType = ComponentTypes::OBJECT;
}

Components::Object::Object(Vector3 position)
{
    _componentType = ComponentTypes::OBJECT;
    _position = position;
}

Components::Object::~Object()
{
}

void Components::Object::setKeys(int keyUp, int keyDown, int keyLeft, int keyRight, int keyBomb) {
    _up = keyUp;
    _down = keyDown;
    _left = keyLeft;
    _right = keyRight;
    _bomb = keyBomb;
}

void Components::Object::setMod(const char *path)
{
    std::string str = path;
    Vector3 ang1 = { DEG2RAD*90, DEG2RAD*200, DEG2RAD*0 };
    Vector3 ang2 = { DEG2RAD*90, DEG2RAD*25, DEG2RAD*0 };
    if (str.compare("Texture/player_gametoons/sceneblue.gltf") == 0  || str.compare("Texture/player_gametoons/scenegreen.gltf") == 0)
        _matrix = MatrixRotateXYZ(ang1);
    else
        _matrix = MatrixRotateXYZ(ang2);
    //if (str.compare("Texture/converse__free/scene.gltf") == 0 || str.compare("Texture/fireball__energy_sphere/scene.gltf"))
    //    _matrix = MatrixRotateXYZ((Vector3){ DEG2RAD*90, DEG2RAD*200, DEG2RAD*0 });
    _model = LoadModel(path);
}

void Components::Object::drawObject()
{
    _model.transform = _matrix;
    DrawModel(_model, _position, 0.24f, RAYWHITE);
}

void Components::Object::setMatrix(int value)
{
    Vector3 ang = {DEG2RAD*90, DEG2RAD*value, DEG2RAD*0 };
    _matrix = MatrixRotateXYZ(ang);
}

Matrix Components::Object::getMatrix()
{
    return _matrix;
}

void Components::Object::setPositionX(float givenPosition)
{
    _position.x += givenPosition;
}

void Components::Object::setPositionZ(float givenPosition)
{
    _position.z += givenPosition;
}

float Components::Object::getPositionX()
{
    return _position.x;
}

float Components::Object::getPositionZ()
{
    return _position.z;
}

Vector2 Components::Object::getPos2D()
{
    Vector2 pos = {_position.x, _position.z};
    return pos;
}

int Components::Object::getUp()
{
    return _up;
}

int Components::Object::getDown()
{
    return _down;
}

int Components::Object::getLeft()
{
    return _left;
}

int Components::Object::getRight()
{
    return _right;
}

Vector3 Components::Object::getPos3D()
{
    return _position;
}

int Components::Object::getHealth()
{
    return _health;
}

void Components::Object::setHealth(int hit)
{
    _health -= hit;
}

int Components::Object::getBomb()
{
    return _bomb;
}

float Components::Object::getSpeed()
{
    return _speed;
}

void Components::Object::setSpeed(float speed)
{
    _speed += speed;
}

float Components::Object::getPower()
{
    return _power;
}

void Components::Object::setPower(float power)
{
    _power += power;
}