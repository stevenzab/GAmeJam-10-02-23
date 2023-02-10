/*
** EPITECH PROJECT, 2023
** GAmeJam-10-02-23
** File description:
** Sprite
*/

#include "../include/Sprite.hpp"

Sprite::Sprite()
{
    if (!texture.loadFromFile("assets/goku.png"))
        return;
    texture.loadFromFile("assets/goku.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(10, 0, 50, 100));
    sprite.setPosition(100, 100);
}

Sprite::~Sprite()
{
}

void Sprite::Init_sprite()
{

    // sprite.setScale(2, 2);
    // sprite.setRotation(90);
    // sprite.setColor(sf::Color(255, 0, 0, 255));
}