/*
** EPITECH PROJECT, 2022
** Draw.cpp
** File description:
** Draw
*/

#include "Draw.hpp"

void Draw::StartDraw()
{
    BeginDrawing();
}

void Draw::EndDraw()
{
    EndDrawing();
}
void Draw::StartDraw3D(std::shared_ptr<Components::Camera> camera)
{
    BeginMode3D(camera->getCamera());
}

void Draw::MyDrawSphere(Vector3 pos, float size, Color color)
{
    DrawSphere(pos, size, color);
}

void Draw::MyDrawModel(Model model, Vector3 pos, float size, Color color)
{
    DrawModel(model, pos, size, color);
}

void Draw::EndDraw3D()
{
    EndMode3D();
}

void Draw::DrawTexture2D(Texture2D texture, int X, int Y, Color color)
{
    DrawTexture(texture, X, Y, color);
}


void Draw::DrawTexte(const char * text, int X, int Y, int size)
{
    DrawText(text, X, Y, size, WHITE);
}

void Draw::MyClearBackground()
{
    ClearBackground(BLACK);
}

void Draw::MyCloseWindow()
{
    CloseWindow(); 
}
 
Image Draw::imageLoader(const char *path)
{
    return LoadImage(path);
}

Texture2D Draw::imageToTexture(Image image)
{
    return LoadTextureFromImage(image);
}

void Draw::SetFlags(int flags)
{
    SetConfigFlags(flags);
}

void Draw::SetWindows(int width, int height, const char * title)
{
    InitWindow(width, height, title);
}

void Draw::setFPS(int fps)
{
    SetTargetFPS(fps);
}

bool Draw::isClosed()
{
    return WindowShouldClose();
}
