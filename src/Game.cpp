/*
** EPITECH PROJECT, 2023
** jam1
** File description:
** Game
*/

#include "../include/Game.hpp"


Game::Game(std::shared_ptr<ResourceAllocator<sf::Texture>> alloc, std::shared_ptr<ResourceAllocator<sf::Font>> font)
{
}

Game::~Game()
{
}

void Game::update()
{
    // update Position
}

bool Game::eventManager(Input n)
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

sf::View Game::getView() const
{
    return _view;
}

void Game::setMouseClick(const std::pair<double, double> &vec)
{
    _click = vec;
}

void Game::draw(Window &win)
{
    //draw stuff ob window
}
