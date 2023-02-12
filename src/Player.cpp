/*
** EPITECH PROJECT, 2023
** GAmeJam-10-02-23
** File description:
** Player
*/

#include "../include/Player.hpp"

Player::Player() : Sprite(500, 300)
{
    _floor = 0;
    count_frame = 0;
    changeX = 0;
    changeY = 0;
    shape.setSize(sf::Vector2f(51,51));
    shape.setPosition(getX(),getY());
}

Player::~Player()
{
}

void Player::update()
{
    // update Position
    shape.setPosition(getX(),getY());

}

void Player::moveRect()
{
    if (count_frame == 7)
        count_frame = 0;
    else
        count_frame++;
    setSpriteRect(count_frame * 51, 51, 80);
    _sprite.setTextureRect(sf::IntRect(count_frame * 51, 0, 51, 80));
}

void Player::up()
{
    if (getY() - 40 > 0)
        changePosition(getX(), getY() - 40);
}

void Player::left()
{
    if (getX() - 40 > 0)
        changePosition(getX() - 40, getY());
}

void Player::right()
{
    if (getX() + 40 < 1000)
        changePosition(getX() + 40, getY());
}

void Player::down()
{
    if (getY() + 40 < 950)
        changePosition(getX(), getY() + 40);
}

void Player::setFloor(int floor, int y)
{
    _floor = floor;
    changePosition(getX(), y);
}

int Player::getFloor() const
{
    return _floor;
}