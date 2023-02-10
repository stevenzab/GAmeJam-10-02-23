/*
** EPITECH PROJECT, 2023
** jam1
** File description:
** Menu
*/

#include "Menu.hpp"


Menu::Menu(std::shared_ptr<ResourceAllocator<sf::Texture>> alloc, std::shared_ptr<ResourceAllocator<sf::Font>> font)
{
}

Menu::~Menu()
{
}

void Menu::update()
{
    // update Position
}

bool Menu::eventManager(Input n)
{
    switch (n) {
        default:
            return false;
    }
}

sf::View Menu::getView() const
{
    return _view;
}

void Menu::setMouseClick(const std::pair<double, double> &vec)
{
    _click = vec;
}

void Menu::draw(Window &win)
{
    //draw stuff ob window
}
