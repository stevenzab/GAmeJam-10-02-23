/*
** EPITECH PROJECT, 2023
** jam1
** File description
** Button
*/

#include "../include/Button.hpp"

Button::Button(int x, int y) : Sprite(x, y)
{
    setSpriteScale(0.5, 0.5);
}

Button::~Button()
{
}

bool Button::isClicked(std::pair<double, double> &clicked)
{
    int x = clicked.first;
    int y = clicked.second;
    if (_x <= x && _y <= y && x <= _x + 249.5 && y <= _y + 129)
        return true;
    return false;
}
