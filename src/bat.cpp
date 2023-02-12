/*
** EPITECH PROJECT, 2023
** GAmeJam-10-02-23
** File description:
** Bat
*/

#include "../include/bat.hpp"

Bat::Bat(int x, int y) : Sprite(x, y)
{
    count_frame = 0;
    changeX = 0;
    changeY = 0;
    shape.setSize(sf::Vector2f(0.2,0.2));
    shape.setPosition(getX(),getY());
}

Bat::~Bat()
{
}

void Bat::update()
{
    // update Position
    changePosition(getX(), getY() + 0.1);
    CheckHitBox(getX(), getY());
    shape.setPosition(getX(),getY());
}

void Bat::moveRect()
{
    if (count_frame == 6)
        count_frame = 0;
    else
        count_frame++;
    setSpriteRect(count_frame * 320, 159, 1080);
    _sprite.setTextureRect(sf::IntRect(count_frame * 320, 0, 320, 159));
}

bool Bat::CheckHitBox(int x, int y)
{
    if (x >= getX() && x <= getX() && y >= getY() && y <= getY())
        return true;
    return false;
}