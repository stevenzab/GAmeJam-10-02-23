/*
** EPITECH PROJECT, 2023
** jam1
** File description:
** Game
*/

#include "../include/Game.hpp"


Game::Game(std::shared_ptr<ResourceAllocator<sf::Texture>> alloc, std::shared_ptr<ResourceAllocator<sf::Font>> font) : _player(), _alloc(alloc), _font(font), _music(), _sound(), _life()
{
    _player.setTextureAllocator(_alloc);
    _player.load("assets/goku.png");
    _player.setSpritePosition(500, 505);
    _player.setSpriteRect(20, 51, 80);
    _music.loadSound("dbz", "assets/music_dbz.ogg");
    _background.setTextureAllocator(_alloc);
    _background.load("assets/Gbackground.png");
    _background.setSpritePosition(-600,0);
    srand(time(NULL));
    _life.push_back(Life(800, 10));
    _life.push_back(Life(850, 10));
    _life.push_back(Life(900, 10));
    for (auto &e: _life) {
        e.setTextureAllocator(_alloc);
        e.setSpriteScale(0.3, 0.3);
        e.load("assets/LIFE1.png");
    }
}

Game::~Game()
{
    _music.stopSound("dbz", "assets/music_dbz.ogg");
}

void Game::CreateBat()
{
    for (int i = 0; i != _bat.size(); i++) {
        if (_bat[i].getX() < 0) {
            _bat.erase(_bat.begin() + i);
        }
    }


    _bat.push_back(Bat(1000, rand() % 1000 + 1));
    for (auto &e: _bat) {
        e.setTextureAllocator(_alloc);
        e.load("assets/bat.png");
        e.setSpritePosition(0,0);
        e.setSpriteRect(0, 320, 159);
        e.setSpriteScale(0.2, 0.2);
    }
}

void Game::update()
{
    // update Position
    for (auto &e: _bat) {
        e.moveRect();
        e.update();
    }
    _player.moveRect();
    CreateBat();
    CheckLoseLife();
}

bool Game::eventManager(Input n)
{
    CheckLoseLife();
    switch (n) {
        case Input::Up:
            _player.up();
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
        case Input::Down:
            _player.down();
            std::cout << "down" << std::endl;
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
    for (auto &e: _bat) {
        e.draw(win);
    }
    _player.draw(win);
    for (auto &e: _life) {
        e.draw(win);
    }

    _music.playSound("dbz", "assets/music_dbz.ogg");
    _music.setLoop("dbz");
}

void Game::LooseLife()
{
    stackHealth = 0;
    for (auto &e: _life) {
        stackHealth += e.GetHealth();
    }
    if (stackHealth == 0)
        std::cout << "You lose" << std::endl;
    for (auto &e: _life) {
        if (e.GetHealth() == 1) {
            e.LoseLife();
            e.load("assets/LIFE0.png");
            break;
        }
    }
}

void Game::CheckLoseLife()
{
    for (auto &e: _bat) {
        if (e.CheckHitBox(_player.getX(), _player.getY()))
            LooseLife();
    }
}