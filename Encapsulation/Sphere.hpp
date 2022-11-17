/*
** EPITECH PROJECT, 2022
** sphere.hpp
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "../System/Draw.hpp"

class Sphere {
    public:
        bool checkCollision(Vector3 pos1, float size1, Vector3 pos2, float size2);
        void CallDrawSphere(Draw *draw, Vector3 pos, float size, Color color);

    protected:
    private:
};

#endif /* !SPHERE_HPP_ */
