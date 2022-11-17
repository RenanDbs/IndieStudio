/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** InputsHandler
*/

#include "InputsHandler.hpp"

encaps::InputsHandler::InputsHandler()
{
}

encaps::InputsHandler::~InputsHandler()
{
}

bool encaps::InputsHandler::isKeyDown(KeyboardKey key) {
    return IsKeyDown(key);
}

bool encaps::InputsHandler::isKeyUp(KeyboardKey key) {
    return IsKeyUp(key);
}

bool encaps::InputsHandler::isKeyPressed(KeyboardKey key) {
    return IsKeyPressed(key);
}

bool encaps::InputsHandler::isKeyReleased(KeyboardKey key) {
    return IsKeyReleased(key);
}
