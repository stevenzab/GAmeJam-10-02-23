/*
** EPITECH PROJECT, 2023
** GAmeJam-10-02-23
** File description:
** WIndow
*/

#include "../Include/Background.hpp"

Background::Background()
{
}

Background::~Background()
{
}
void Background::Init_background() {
    sf::Texture texture;
    texture.loadFromFile("../Assets/background.png");
    sf::Sprite background;
    background.setTexture(texture);
    background.setPosition(0,0);
//    texture.create(1920, 1080);

}
