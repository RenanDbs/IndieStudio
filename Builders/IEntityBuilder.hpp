/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** IBuilder
*/

#ifndef IENTITYBUILDER_HPP_
#define IENTITYBUILDER_HPP_

#include "../Entity/Entity.hpp"
#include <memory>

class IEntityBuilder {
    public:
        ~IEntityBuilder() = default;
        virtual void reset(position_t position) = 0;
        virtual void addComps() = 0;
        virtual Entity &getEntity() = 0;
};

#endif /* !IENTITYBUILDER_HPP_ */
