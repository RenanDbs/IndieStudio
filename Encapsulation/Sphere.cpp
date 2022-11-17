/*
** EPITECH PROJECT, 2022
** sphere.cpp
** File description:
** Sphere
*/

#include "Sphere.hpp"

bool Sphere::checkCollision(Vector3 pos1, float size1, Vector3 pos2, float size2)
{
    return CheckCollisionSpheres(pos1, size1, pos2, size2);
}

void Sphere::CallDrawSphere(Draw *draw, Vector3 pos, float size, Color color)
{
    draw->MyDrawSphere(pos, size, color);
}