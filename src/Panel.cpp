/*
** EPITECH PROJECT, 2023
** jam1
** File description:
** Panel
*/

#include "../include/Panel.hpp"

Panel::Panel() : Sprite(0, 800), _juan(650, 500)
{
    setSpriteScale(2.1, 2.1);
}

Panel::~Panel()
{
}

void Panel::setFontAllocator(std::shared_ptr<ResourceAllocator<sf::Font>> font)
{
    _font = font;

    std::shared_ptr<sf::Font> text = _font->Get("DungeonFont");
    _name.setString("Juan seed");
    _name.setFont(*text);
    _name.setPosition(20, 830);
    _name.setFillColor(sf::Color::Black);
    _name.setCharacterSize(20);
    _text.setString("You're too late. The multiverse has already been corrupted. There is nothing to be done now.");
    _text.setCharacterSize(20);
    _text.setFont(*text);
    _text.setPosition(20,870);
    _text.setFillColor(sf::Color::Black);
    _text1.setString("Not even the bearer of creation and destruction could stop me. I WON!!!");
    _text1.setCharacterSize(20);
    _text1.setFont(*text);
    _text1.setPosition(20,900);
    _text1.setFillColor(sf::Color::Black);
    _juan.setTextureAllocator(_alloc);
    _juan.load("Wizard");
    _juan.setSpriteScale(14.0, 14.0);
    _juan.setSpriteRect(0, 35, 33);
}

void Panel::write(Window &win)
{
    win.draw(_name);
    win.draw(_text);
    win.draw(_text1);
    _juan.draw(win);
}