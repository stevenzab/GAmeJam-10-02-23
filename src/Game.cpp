/*
** EPITECH PROJECT, 2023
** jam1
** File description:
** Game
*/

#include "../include/Game.hpp"


Game::Game(std::shared_ptr<ResourceAllocator<sf::Texture>> alloc, std::shared_ptr<ResourceAllocator<sf::Font>> font) : _player(), _alloc(alloc), _font(font), _music(), _sound()
{
    _player.setTextureAllocator(_alloc);
    _player.load("assets/goku.png");
    _player.setSpritePosition(500, 505);
    _player.setSpriteRect(80, 50, 80);
    _music.loadSound("dbz", "assets/music_dbz.ogg");
    _background.setTextureAllocator(_alloc);
    _background.load("assets/Gbackground.png");
    _background.setSpritePosition(-600,0);
    _bat.setTextureAllocator(_alloc);
    _bat.load("assets/bat.png");
    _bat.setSpritePosition(0,0);
    _bat.setSpriteRect(0, 320, 159);
}

Game::~Game()
{
    _music.stopSound("dbz", "assets/music_dbz.ogg");
}

void Game::update()
{
    // update Position
    _bat.moveRect();
    _player.moveRect();
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
    _background.draw(win);
    _bat.draw(win);
    _player.draw(win);

    _music.playSound("dbz", "assets/music_dbz.ogg");
    _music.setLoop("dbz");
}
