/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_
#include "IComponent.hpp"

namespace Components {
    class Text : public IComponent {
        public:
            Text(const char * Text, int X, int Y, int fontSize, Color Color);
            ~Text() = default;
            void drawText();
        private:
            const char* _Text;
            int _X;
            int _Y;
            int _fontSize;
            Color _Color;
    };
}

#endif /* !TEXT_HPP_ */
