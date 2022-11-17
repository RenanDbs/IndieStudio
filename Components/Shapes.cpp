/*
** EPITECH PROJECT, 2022
** shapes.cpp
** File description:
** Shapes
*/

#include "Shapes.hpp"

Components::Shapes::Shapes(Vector3 position, float width, float height, float lenght, Color color)
{
    _componentType = ComponentTypes::SQUARE;
    _position = position;
    _width = width;
    _height = height;
    _lenght = lenght;
    _color = color;
    _type = 1;
    _printable = 1;
    _bonusType = 0;
    _up = 1;
}

Components::Shapes::Shapes(Vector3 position, float radius, Color color)
{
    _componentType = ComponentTypes::SPHERE;
    _position = position;
    _radius = radius;
    _color = color;
    _type = 2;
}

Components::Shapes::~Shapes()
{
}

Vector3 Components::Shapes::getPosition() const
{
    return _position;
}

Vector2 Components::Shapes::getPos2D() const
{
    Vector2 pos = {_position.x, _position.z};
    return pos;
}

Model Components::Shapes::getModel() const
{
    return _model;
}
void Components::Shapes::drawShape()
{
    if (_type ==  1) {
        DrawCubeTexture(_texture, _position, _width, _height, _lenght, _color);
    } else { 
        DrawSphere(_position, _radius, _color);
    }
}

void Components::Shapes::setPathText(const char *path)
{
    _texture = LoadTexture(path);
}

void Components::Shapes::setShapes() {
    _texture = LoadTexture("./Texture/box.png");
}

Color *Components::Shapes::getMapPixels() const
{
    return _mapPixels;
}

void Components::Shapes::setMap() {
    Image image = LoadImage("./Texture/cubicmap.png");
    _position = { -7.5f, 0.0f, -8.0f };
    _mapPixels = LoadImageColors(image);
    _cubicmap = LoadTextureFromImage(image);
    Mesh mesh = GenMeshCubicmap(image, {1.0f, 1.0f, 1.0f});
    _model = LoadModelFromMesh(mesh);
    _texture = LoadTexture("./Texture/TEST_WALL.png");
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
}

Texture2D Components::Shapes::getCubicmap() const
{
    return _cubicmap;
}

void Components::Shapes::drawMap()
{
    DrawModel(_model, _position, 1.0f, WHITE );
}

void Components::Shapes::setPositionX(float givenPosition)
{
    _position.x += givenPosition; // trunncate needed
}

void Components::Shapes::setPositionZ(float givenPosition)
{
    _position.z += givenPosition; // truncate needed
}

void Components::Shapes::setPositionY(float givenPosition)
{
    _position.y += givenPosition;
}

float Components::Shapes::getPositionY() const
{
    return _position.y;
}

float Components::Shapes::getPositionX() const
{
    return _position.x;
}

float Components::Shapes::getPositionZ() const
{
    return _position.z;
}

void Components::Shapes::drawMinMap(std::shared_ptr<Components::Object> obj, std::shared_ptr<Components::Object> obj1, std::shared_ptr<Components::Object> obj2, std::shared_ptr<Components::Object> obj3, std::shared_ptr<Components::Shapes> map)
{

    int playerCellX = (int)(obj->getPos2D().x - map->getPosition().x + 0.5f);
    int playerCellY = (int)(obj->getPos2D().y - map->getPosition().z + 0.5f);
    int playerCellX1 = (int)(obj1->getPos2D().x - map->getPosition().x + 0.5f);
    int playerCellY1 = (int)(obj1->getPos2D().y - map->getPosition().z + 0.5f);
    int playerCellX2 = (int)(obj2->getPos2D().x - map->getPosition().x + 0.5f);
    int playerCellY2 = (int)(obj2->getPos2D().y - map->getPosition().z + 0.5f);
    int playerCellX3 = (int)(obj3->getPos2D().x - map->getPosition().x + 0.5f);
    int playerCellY3 = (int)(obj3->getPos2D().y - map->getPosition().z + 0.5f);
    Vector2 pos = { GetScreenWidth() - map->getCubicmap().width*4.0f - 20, 20.0f };


    DrawTextureEx(map->getCubicmap(), pos, 0.0f, 4.0f, WHITE);
    DrawRectangle(GetScreenWidth() - map->getCubicmap().width*4 - 20 + playerCellX*4, 20 + playerCellY*4, 4, 4, BLUE);
    DrawRectangle(GetScreenWidth() - map->getCubicmap().width*4 - 20 + playerCellX1*4, 20 + playerCellY1*4, 4, 4, RED);
    DrawRectangle(GetScreenWidth() - map->getCubicmap().width*4 - 20 + playerCellX2*4, 20 + playerCellY2*4, 4, 4, GREEN);
    DrawRectangle(GetScreenWidth() - map->getCubicmap().width*4 - 20 + playerCellX3*4, 20 + playerCellY3*4, 4, 4, YELLOW);
}

int Components::Shapes::isPrintable() const
{
    return _printable;
}

void Components::Shapes::setPrintable(int i)
{
    _printable = i;
}

int Components::Shapes::getUp() const
{
    return _up;
}

void Components::Shapes::setUp(int i)
{
    _up = i;
}

void Components::Shapes::setBonusType(int i)
{
    _bonusType = i;
}

int Components::Shapes::getBonusType() const
{
    return _bonusType;
}
