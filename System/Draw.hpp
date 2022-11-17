/*
** EPITECH PROJECT, 2022
** Draw.hpp
** File description:
** Draw
*/

#ifndef DRAW_HPP_
#define DRAW_HPP_

#include "../Components/IComponent.hpp"
#include "../Components/Camera.hpp"
#include <memory>

class Draw {
    public:
        void StartDraw();
        void EndDraw();
        void StartDraw3D(std::shared_ptr<Components::Camera> camera);
        void EndDraw3D();
        void DrawTexture2D(Texture2D texture, int X, int Y, Color color);
        void MyClearBackground();
        void MyCloseWindow();
        Image imageLoader(const char *path);
        Texture2D imageToTexture(Image image);
        void setFPS(int fps);
        void SetWindows(int width, int height, const char * title);
        void SetFlags(int flags);
        bool isClosed();
        void MyDrawSphere(Vector3 pos, float size, Color color);
        void MyDrawModel(Model model, Vector3 pos, float size, Color color);
        void DrawTexte(const char * text, int X, int Y, int size);
        bool checkCollision(Vector3 pos1, int size1, Vector3 pos2, int size2);


    protected:
    private:
};

#endif /* !DRAW_HPP_ */
