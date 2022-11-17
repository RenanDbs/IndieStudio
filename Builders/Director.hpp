/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Director
*/

#ifndef DIRECTOR_HPP_
#define DIRECTOR_HPP_

#include "./IEntityBuilder.hpp"
#include "./CameraBuilder.hpp"
#include "./MapBuilder.hpp"
#include "./PlayerBuilder.hpp"

enum EntityTypes {
        BASE_CAMERA,
        MAP,
        PLAYER0,
        PLAYER1,
        PLAYER2,
        PLAYER3,
        CUBE/*,
        SPHERE*/
};

class Director {
    public:
        Director();
        ~Director();
        Entity &make(EntityTypes type, position_t position);

    private:
        CameraBuilder _cameraBuilder;
        MapBuilder _mapBuilder;
        PlayerBuilder _playerBuilder;
};

#endif /* !DIRECTOR_HPP_ */
