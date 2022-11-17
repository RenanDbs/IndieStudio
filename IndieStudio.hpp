/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Entity
*/

#ifndef INDIESTUDIO_HPP_
#define INDIESTUDIO_HPP_

#include "Entity/Entity.hpp"
#include "Builders/IEntityBuilder.hpp"
#include "Builders/Director.hpp"
#include "System/Menu.hpp"
#include "System/Time.hpp"
#include "System/Draw.hpp"
#include "Encapsulation/Sphere.hpp"
#include "Encapsulation/InputsHandler.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <memory>

typedef enum GameState {
    INTRO,
    INTRO2,
    MENU,
    GAME,
    OPTIONS,
    END
} GameState;

class IndieStudio {
    public:
        IndieStudio() = default;
        void stockCSVMenuInVec();
        std::vector<std::vector<int>> getCsvBox();
        void buildFirstIntro(Draw &draw, Texture2D texture);
        int getOpacityTransition();
        void setOpacityTransition(int opacity);
        void setStateTransition(int state);
    private:
        std::vector<std::vector<int>> _CsvBox;
        int _opacityTransition = 1;
        int _stateTransition = 0;
        encaps::InputsHandler _inputsHandler = encaps::InputsHandler();
};

#endif /* INDIESTUDIO_HPP_ */
