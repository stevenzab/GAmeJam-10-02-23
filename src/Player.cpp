/*
** EPITECH PROJECT, 2023
** GAmeJam-10-02-23
** File description:
** Player
*/

#include "../include/Player.hpp"

Player::Player() : Sprite(500, 500)
{
    count_frame = 0;
    changeX = 0;
    changeY = 0;
}

Player::~Player()
{
}

void Player::update()
{
    // update Position

}

void Player::moveRect()
{
    if (count_frame == 8)
        count_frame = 0;
    else
        count_frame++;
    setSpriteRect(count_frame * 50.8, 51, 80);
    _sprite.setTextureRect(sf::IntRect(count_frame * 50.8, 0, 51, 80));
}

void Player::jump()
{

}

void Player::left()
{
    changePosition(getX() - 15, getY());
}

void Player::right()
{
    changePosition(getX() + 15, getY());
}