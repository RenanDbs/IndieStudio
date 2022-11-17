/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** InputsHandler
*/

#ifndef INPUTSHANDLER_HPP_
    #define InputsHandler_HPP_

#include "raylib.h"

namespace encaps {
    class InputsHandler {
        public:
            InputsHandler() = default;
            ~InputsHandler() = default;
            bool isKeyDown(KeyboardKey key);
            bool isKeyUp(KeyboardKey key);
            bool isKeyPressed(KeyboardKey key);
            bool isKeyReleased(KeyboardKey key);

        protected:
        private:
    };
}

#endif /* !INPUTSHANDLER_HPP_ */
