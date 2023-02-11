/*
** EPITECH PROJECT, 2023
** GAmeJam-10-02-23
** File description:
** Bat
*/

#include "../include/bat.hpp"

Bat::Bat() : Sprite(500, 500)
{
    count_frame = 0;
    changeX = 0;
    changeY = 0;
}

Bat::~Bat()
{
}

void Bat::update()
{
    // update Position

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