/*
** EPITECH PROJECT, 2022
** shapes.hpp
** File description:
** Shapes
*/

#ifndef SHAPES_HPP_
#define SHAPES_HPP_

#include "IComponent.hpp"
#include "Object.hpp"
#include <memory>

namespace Components {
    class Shapes : public IComponent{
        public:
            Shapes() = default;
            Shapes(Vector3 position, float width, float height, float lenght, Color color);
            Shapes(Vector3 position, float radius, Color color);
            ~Shapes();
            void drawShape();
            void setMap();
            void setShapes();
            void drawMap();
            void drawMinMap(std::shared_ptr<Components::Object> obj, std::shared_ptr<Components::Object> obj1, std::shared_ptr<Components::Object> obj2, std::shared_ptr<Components::Object> obj3, std::shared_ptr<Components::Shapes> map);
            void setPositionX(float givenPosition);
            void setPositionZ(float givenPosition);
            void setPositionY(float givenPosition);
            float getPositionY() const;
            float getPositionX() const;
            float getPositionZ() const;
            Vector2 getPos2D() const;
            Texture2D getCubicmap() const;
            Color *getMapPixels() const;
            Model getModel() const;
            Vector3 getPosition() const;
            int isPrintable() const;
            void setPathText(const char *path);
            void setPrintable(int i);
            int getUp() const;
            void setUp(int i);
            int getBonusType() const;
            void setBonusType(int i);

        private:
            int _type;
            Texture2D _texture;
            Vector3 _position;
            Texture2D _cubicmap;
            Color *_mapPixels;
            float _radius;
            float _width;
            float _height;
            float _lenght;
            Color _color;
            Model _model;
            int _bonusType;
            int _printable;
            int _up;
    };
}

#endif /* !SHAPES_HPP_ */
