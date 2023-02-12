/*
** EPITECH PROJECT, 2023
** GAmeJam-10-02-23
** File description:
** Life
*/

#include "../include/Life.hpp"

Life::Life(int x, int y) : Sprite(x, y)
{
    _health = 1;
}

Life::~Life()
{
}

int Life::GetHealth()
{
    return _health;
}

void Life::LoseLife()
{
    _health--;
}