/*
** EPITECH PROJECT, 2022
** Time.cpp
** File description:
** Time
*/

#include "Time.hpp"

Time::Time()
{
    _time = GetTime();
}

double Time::GetCurrentTime()
{
    return GetTime();
}

void Time::SetCurrentTime()
{
    _time = GetTime();
}

bool Time::CheckTime(double offset)
{
    if (_time + offset <= GetTime())
        return true;
    else
        return false;
}