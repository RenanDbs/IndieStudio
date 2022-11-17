/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Collision
*/

#include "Collision.hpp"
#include "Shapes.hpp"

void Components::Collision::getModelBounding(Model model) {
    GetModelBoundingBox(model);
}

bool Components::Collision::checkCollision(Texture2D cubicMap, Vector3 mapPos, Vector3 playerPos, Color *color)
{    
    for (int y = 0; y < cubicMap.height; y++)
    {
        for (int x = 0; x < cubicMap.width; x++)
        {   
            Vector3 tes = {mapPos.x - 0.0f + x*1.0f, 0.0f,  mapPos.z- 0.0f + y*1.0f};
            if ((color[y*cubicMap.width + x].r == 255) && CheckCollisionSpheres(tes, 0.4f, playerPos, 0.5f))
                return true;
        }
    }
    return false;
}

bool Components::Collision::checkBoxCollision(const std::vector<std::shared_ptr<Components::Shapes>> box, size_t nbbox ,Vector3 playerPos)
{
    for (size_t i = 0; i < nbbox; i++)
    {
        // std::cout << "Checking collision with boxes" << std::endl;
        if (CheckCollisionSpheres(box[i]->getPosition(), 0.4f, playerPos, 0.5f) && box[i]->isPrintable() == 1) {
            // DrawSphere(box[i]->getPosition(), 0.6, PURPLE);
            return true;
        }
    }
    return false;
}
