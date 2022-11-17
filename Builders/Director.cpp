/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Director
*/

#include "Director.hpp"

Director::Director()
{
}

Director::~Director()
{
}

Entity &Director::make(EntityTypes type, position_t position) {
    switch (type) {
        case EntityTypes::BASE_CAMERA:
            _cameraBuilder.reset(position);
            _cameraBuilder.setCameraComp({0.0, 0.0, 0.0}, {0.0, 10.0, 0.0});
            // _cameraBuilder.setCameraComp({0.0, 0.0, 0.0}, {0.0, 10.0, -10.0});
            _cameraBuilder.addComps();
            return _cameraBuilder.getEntity();
        case EntityTypes::MAP:
            _mapBuilder.reset(position);
            _mapBuilder.setSquareComp(1.0, 1.0, 1.0, GRAY);
            _mapBuilder.setCollisionComp();
            _mapBuilder.addComps();
            return _mapBuilder.getEntity();
        case EntityTypes::PLAYER0:
            _playerBuilder.reset(position);
            _playerBuilder.setModel(KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE);
            break;
        case EntityTypes::PLAYER1:
            _playerBuilder.reset(position);
            _playerBuilder.setModel(KEY_W, KEY_S, KEY_A, KEY_D, KEY_Q);
            break;
        case EntityTypes::PLAYER2:
            _playerBuilder.reset(position);
            _playerBuilder.setModel(KEY_Y, KEY_H, KEY_G, KEY_J, KEY_U);
            break;
        case EntityTypes::PLAYER3:
            _playerBuilder.reset(position);
            _playerBuilder.setModel(KEY_F, KEY_V, KEY_C, KEY_B, KEY_X);
            break;
        default:
            throw "Invalid EntityTypes";
    }
    _playerBuilder.setMovement();
    _playerBuilder.setCollision();
    _playerBuilder.setBomb();
    _playerBuilder.addComps();
    // _playerBuilder.getEntity().getCollisionComp();
    return _playerBuilder.getEntity();
}
