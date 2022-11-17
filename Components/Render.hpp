/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Render
*/

#ifndef RENDER_HPP_
#define RENDER_HPP_

#include "IComponent.hpp"

namespace Components {
    class Render : public IComponent {
        public:
            Render(Model model, Texture2D texture);
            ~Render();
        private:
            Model _model;
            Texture2D _texture;
    };
}

#endif /* !RENDER_HPP_ */
