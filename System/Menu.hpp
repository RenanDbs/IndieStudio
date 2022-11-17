/*
** EPITECH PROJECT, 2022
** Menu.hpp
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "../Components/IComponent.hpp"

class Menu {
    public:
        Menu();
        ~Menu();
        void DrawMenu();
        void DrawEndMenu();
        int DrawOptions();
        int CheckMenu();
        void PlayMusic();
        void PlayBoom();
        void UpdateMusic();
        void PauseMusic();
        void DrawEnd(int winner);
    private:
        Sound _music;
        Sound _boom;
        Texture2D _texture;
        Rectangle _rect1;
        Rectangle _rect2;
        Rectangle _rect3;
        Rectangle _rect4;
        Rectangle _rect5;
        Rectangle _rect6;
        Rectangle _rect7;
        Rectangle _rect8;
        Rectangle _rect9;
        Vector2 _mouspos;
        Texture2D _texture1Btn;
        Texture2D _texture2Btn;
        Texture2D _texture3Btn;
        Texture2D _texture4Btn;
        Texture2D _textureMenuBtn;
        Texture2D _textureOptionBtn;
        Texture2D _textureUpBtn;
        Texture2D _textureDownBtn;
        Texture2D _textureReturnBtn;
        Texture2D _textureMuteBtn;
        Texture2D _textureTitle;
        bool _pause = true;
        float _volume = 0.5f;
        float _screenWidth = 1920;
        float _screenHeight = 1080;

};

#endif /* !MENU_HPP_ */
