/*
** EPITECH PROJECT, 2023
** jam1
** File description:
** Menu
*/

#include "../include/Menu.hpp"


Menu::Menu(std::shared_ptr<ResourceAllocator<sf::Texture>> alloc, std::shared_ptr<ResourceAllocator<sf::Font>> font) : _player(), _alloc(alloc), _font(font)
{
    _player.setTextureAllocator(_alloc);
    _player.load("assets/goku.png");
    _player.setSpritePosition(0, 0);
    _player.setSpriteRect(80, 50, 80);
}

Menu::~Menu()
{
}

void Menu::update()
{
    // update Position
    _player.moveRect();
}

bool Menu::eventManager(Input n)
{
    switch (n) {
        case Input::Up:
            _player.jump();
            std::cout << "jump" << std::endl;
            return false;
        case Input::Left:
            _player.left();
            std::cout << "left" << std::endl;
            return false;
        case Input::Right:
            _player.right();
            std::cout << "right" << std::endl;
            return false;
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
    _player.draw(win);
}
