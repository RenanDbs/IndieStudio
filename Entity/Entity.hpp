/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_
#include "../Components/IComponent.hpp"
#include "../Components/Camera.hpp"
#include "../Components/Shapes.hpp"
#include "../Components/Object.hpp"
#include "../Components/Movements.hpp"
#include "../Components/Text.hpp"
#include "../Components/Collision.hpp"
#include "../Components/Bomb.hpp"
#include <memory>
// #include "../Components/Ia.hpp"

class Entity;

enum direction {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    POSE_BOMB,
    NONE
};

namespace Components {
    class Ia : public IComponent {
        public:
            Ia(int _id);
            ~Ia();
            int getId();
            bool checkCollision(Entity &entity, Entity &box, Entity &map);
            enum direction getNextMove(Entity &entity, Entity &map, Entity &box, std::vector<Entity> &players, std::vector<std::shared_ptr<Components::Bomb>> bombVect);
            enum direction moveIA(std::vector<Entity> &players, int currentPlayer, Entity &map, Entity &box, const std::vector<std::shared_ptr<Components::Shapes>> boxVec, std::vector<std::shared_ptr<Components::Bomb>> bombVect);
            float getDistance();
            void setDistance(float distance);
            direction getDirection();
            void setDirection(direction dir);
            bool isBombOnPath(Entity &player, std::vector<std::shared_ptr<Components::Bomb>> bombVect);
            float distanceBetweenTwoPoints(Vector2 point1, Vector2 point2);
            void addDodgingBomb(std::shared_ptr<Components::Bomb> bomb);
            std::vector<std::shared_ptr<Components::Bomb>> getDodgingBomb(void);
            bool isDodgingBomb(void);
            void dodgingBomb(bool state);
        private:
            /* data */
            float _distance = 0;
            direction _direction = NONE;
            bool _isDodgingBomb = false;
            std::vector<std::shared_ptr<Components::Bomb>> _coorDodgingBomb;
            int _id;
    };

}

struct position_t {
    float x;
    float y;
    float z;
};

class Entity {
    public:
        Entity() = default;
        Entity(position_t position);
        ~Entity();
        Vector3 getPosition3D();
        void addComponents(std::vector<std::shared_ptr<Components::IComponent>> components);
        void addBox(std::shared_ptr<Components::Shapes>);
        std::vector<std::shared_ptr<Components::Shapes>> getBoxVec();
        std::shared_ptr<Components::Camera>getCameraComp() const;
        std::shared_ptr<Components::Shapes>getShapesComp();
        std::shared_ptr<Components::Object> getObjectComp();
        std::shared_ptr<Components::Movements>getMovementComp();
        std::shared_ptr<Components::Text>getTextComp();
        std::shared_ptr<Components::Collision>getCollisionComp();
        std::shared_ptr<Components::Bomb>getBombComp();
        std::shared_ptr<Components::Shapes>getBoxComp(int i);
        std::shared_ptr<Components::Ia>getIAComp();
        size_t getnbBox();
        void setNbBox(size_t);

    private:
        std::vector<std::shared_ptr<Components::IComponent>> _components;
        position_t _position;
        size_t _nbBox = 0;
        std::vector<std::shared_ptr<Components::Shapes>> _vecBox;
};

#endif /* !ENTITY_HPP_ */
