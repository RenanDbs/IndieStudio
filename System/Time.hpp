/*
** EPITECH PROJECT, 2022
** Time.hpp
** File description:
** Time
*/

#ifndef TIME_HPP_
#define TIME_HPP_

#include "../Components/IComponent.hpp"
#include "../IndieStudio.hpp"

class Time {
    public:
        Time();
        double GetCurrentTime();
        bool CheckTime(double offset);
        void SetCurrentTime();

    private:
        double _time;
};

#endif /* !TIME_HPP_ */
