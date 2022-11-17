/*
** EPITECH PROJECT, 2022
** Menu.cpp
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu()
{
    InitAudioDevice();
    _music = LoadSound("./Texture/MUSIC.mp3");
    _boom = LoadSound("./Texture/BOOM.mp3");
    _texture = LoadTexture("./Texture/Menu.png");
    _rect1 = {15, _screenHeight / 1.75f, 200, 50};
    _rect2 = {15, _screenHeight / 1.55f, 200, 50};
    _rect3 = {15, _screenHeight / 1.40f, 200, 50};
    _rect4 = {15, _screenHeight / 1.28f, 200, 50};
    _rect5 = {15, _screenHeight / 1.18f, 200, 50};
    _rect6 = {15, _screenHeight / 1.75f, 400, 100};
    _rect7 = {15, _screenHeight / 1.20f, 400, 100};
    _rect8 = {1000, _screenHeight / 1.75f, 400, 100};
    _rect9 = {1000, _screenHeight / 1.20f, 400, 100};
    Image image1Btn = LoadImage("./Texture/1Btn.png");
    Image image2Btn = LoadImage("./Texture/2Btn.png");
    Image image3Btn = LoadImage("./Texture/3Btn.png");
    Image image4Btn = LoadImage("./Texture/4Btn.png");
    Image imageMenuBtn = LoadImage("./Texture/MenuBtn.png");
    Image imageOptionBtn = LoadImage("./Texture/OptionBtn.png");
    Image imageUpBtn = LoadImage("./Texture/+Btn.png");
    Image imageDownBtn = LoadImage("./Texture/-Btn.png");
    Image imageReturnBtn = LoadImage("./Texture/ReturnBtn.png");
    Image imageMuteBtn = LoadImage("./Texture/MuteBtn.png");
    Image imageTitle = LoadImage("./Texture/Title.png");
    _texture1Btn = LoadTextureFromImage(image1Btn);
    _texture2Btn = LoadTextureFromImage(image2Btn);
    _texture3Btn = LoadTextureFromImage(image3Btn);
    _texture4Btn = LoadTextureFromImage(image4Btn);
    _textureMenuBtn = LoadTextureFromImage(imageMenuBtn);
    _textureOptionBtn = LoadTextureFromImage(imageOptionBtn);
    _textureUpBtn = LoadTextureFromImage(imageUpBtn);
    _textureDownBtn = LoadTextureFromImage(imageDownBtn);
    _textureReturnBtn = LoadTextureFromImage(imageReturnBtn);
    _textureMuteBtn = LoadTextureFromImage(imageMuteBtn);
    _textureTitle = LoadTextureFromImage(imageTitle);
}

Menu::~Menu()
{
}

void Menu::PlayMusic()
{
    PlaySoundMulti(_music);
}

void Menu::PlayBoom()
{
    PlaySoundMulti(_boom);    
}

void Menu::UpdateMusic()
{
    PlaySound(_music);
}

void Menu::PauseMusic()
{

    _mouspos = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(_mouspos, _rect6))
    {
        if (_pause) {
            StopSoundMulti();
            _pause = false;
        } else {
            PlaySoundMulti(_music);
            _pause = true;
        }
    }
}

void Menu::DrawMenu()
{
    DrawTexture(_texture, 0, 0, WHITE);
    DrawTexture(_textureTitle, 600, 40, RAYWHITE);
    DrawTexture(_texture1Btn, 15, (int)(_screenHeight / 1.75), RAYWHITE);
    DrawTexture(_texture2Btn, 15, (int)(_screenHeight / 1.55), RAYWHITE);
    DrawTexture(_texture3Btn, 15, (int)(_screenHeight / 1.40), RAYWHITE);
    DrawTexture(_texture4Btn, 15, (int)(_screenHeight / 1.28), RAYWHITE);
    DrawTexture(_textureOptionBtn, 15, (int)(_screenHeight / 1.18), RAYWHITE);
}

void Menu::DrawEndMenu()
{
    DrawTexture(_textureMenuBtn, 15, (int)(_screenHeight / 1.28), RAYWHITE);
    DrawTexture(_textureOptionBtn, 15, (int)(_screenHeight / 1.18), RAYWHITE);
}


int Menu::DrawOptions()
{
    DrawTexture(_texture, 0, 0, WHITE);
    DrawTexture(_textureMuteBtn, 15, (int)(_screenHeight / 1.75f), RAYWHITE);
    _mouspos = GetMousePosition();
    DrawTexture(_textureReturnBtn, 15, (int)(_screenHeight / 1.20f), RAYWHITE);
    DrawTexture(_textureUpBtn, 1000, (int)(_screenHeight / 1.75f), RAYWHITE);
    DrawTexture(_textureDownBtn, 1000, (int)(_screenHeight / 1.20f), RAYWHITE);
    
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(_mouspos, _rect8) && _volume < 1.0f) {        
        _volume += 0.10f;
        SetSoundVolume(_music, _volume);
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(_mouspos, _rect9) && _volume > 0.0f) {
        _volume -= 0.10f;
        SetSoundVolume(_music, _volume);
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(_mouspos, _rect7))
        return (2);
    return (0);
}

int Menu::CheckMenu()
{
    _mouspos = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(_mouspos, _rect1))
        return(1);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(_mouspos, _rect2))
        return(2);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(_mouspos, _rect3))
        return(3);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(_mouspos, _rect4))
        return(4);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(_mouspos, _rect5))
        return(5);
    return(-1);
}

void Menu::DrawEnd(int winner)
{
    if (winner == 1)
        DrawText("Player 1 Win", 650, 600, 100, BLUE);
    if (winner == 2)
        DrawText("Player 2 Win", 650, 600, 100, RED);
    if (winner == 3)
        DrawText("Player 3 Win", 650, 600, 100, GREEN);
    if (winner == 4)
        DrawText("Player 4 Win", 650, 600, 100, YELLOW);
}
