/*
** EPITECH PROJECT, 2022
** bomb.hpp
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "IComponent.hpp"
#include "Shapes.hpp"
#include "Object.hpp"
#include "../System/Menu.hpp"
#include "../Encapsulation/Sphere.hpp"
#include "../System/Draw.hpp"


namespace Components {
    class Bomb : public IComponent{
        public:
            Bomb();
            ~Bomb() = default;
            Vector3 setBomb(std::shared_ptr<Components::Object> player);
            std::vector<std::shared_ptr<Components::Shapes>> spawnBomb(Vector3 pos, std::vector<std::shared_ptr<Components::Object>> objectComps, std::vector<std::shared_ptr<Components::Shapes>> box, size_t nbrBox, std::vector<std::shared_ptr<Components::Shapes>> bonus, float power, std::vector<std::shared_ptr<Components::Bomb>> &bombVector, Menu &menu, Draw &draw, Sphere &sphere);
            // std::vector<Components::Shapes> &spawnBomb(Vector3 pos, std::vector<Components::Object> &objectComps, std::vector<Components::Shapes> &box, size_t nbBox, std::vector<Components::Shapes> &bonus, float power, std::vector<Components::Bomb> &bombvector);
            void setTextBomb();
            void setPosition(Vector3 position);
            Vector3 getPosition() const;
            void setPoseBomb(bool poseBomb);
        private:
            Texture2D _texture;
            bool _poseBomb = false;
            int _state;
            int _hitP1;
            int _hitP2;
            int _hitP3;
            int _hitP4;
            double _time = -9.9;
            Vector3 _tmp;
            Model _modelBomb;
            Model _modelProj;
    };
}

#endif /* !BOMB_HPP_ */
