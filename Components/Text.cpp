/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Text
*/

#include "Text.hpp"

Components::Text::Text(const char * Text, int X, int Y, int fontSize, Color Color) {
    _componentType = ComponentTypes::TEXT;
    _Text = Text;
    _X = X;
    _Y = Y;
    _fontSize = fontSize;
    _Color = Color;
}

void Components::Text::drawText() {
    DrawText(_Text, _X, _Y, _fontSize, _Color);
}
