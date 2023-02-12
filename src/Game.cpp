/*
** EPITECH PROJECT, 2023
** jam1
** File description:
** Game
*/

#include "../include/Game.hpp"


Game::Game(std::shared_ptr<ResourceAllocator<sf::Texture>> alloc, std::shared_ptr<ResourceAllocator<sf::Font>> font) : _player(), _alloc(alloc), _font(font), _music(), _sound(), _life()
{
    srand(time(NULL));
    _player.setTextureAllocator(_alloc);
    _player.load("assets/goku.png");
    _player.setSpritePosition(500, 505);
    _player.setSpriteRect(0, 51, 80);
    _music.loadSound("dbz", "assets/music_dbz.ogg");
    _background.setTextureAllocator(_alloc);
    _background.load("assets/Gbackground.png");
    _background.setSpritePosition(-600,0);
    _life.push_back(Life(800, 10));
    _life.push_back(Life(850, 10));
    _life.push_back(Life(900, 10));
    for (auto &e: _life) {
        e.setTextureAllocator(_alloc);
        e.setSpriteScale(0.3, 0.3);
        e.load("assets/LIFE1.png");
    }
    for (int i = 0; i != 69; i++) {
        _layer.push_back(Layer(i));
        _layer[i].setTextureAllocator(_alloc);
    }
    std::shared_ptr<sf::Font> text = _font->Get("DungeonFont");
    _score.setString("00000");
    _score.setFont(*text);
    _score.setPosition(20, 20);
    _score.setFillColor(sf::Color::White);
    _score.setCharacterSize(30);
    _bossBattle = false;
    _panel.setTextureAllocator(_alloc);
    _panel.setFontAllocator(_font);
    _panel.load("panel");
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
    for (auto &e : _layer) {
        if (e.getLayerNum() == _player.getFloor()) {
            std::pair<double, double> hole = e.getHole();
            int x = _player.getX();
            if (x > hole.first && x < hole.second)
                _player.setFloor(e.getLayerNum() + 1, e.getLayerY() + 5);
            else
                _player.setFloor(e.getLayerNum(), e.getLayerY());
        }
        e.update();
    }
    if (_player.getFloor() < 10)
        _score.setString("0000" + std::to_string(_player.getFloor()));
    else
        _score.setString("000" + std::to_string(_player.getFloor()));
    if (_player.getFloor() == 69)
        _bossBattle = true;
}

bool Game::eventManager(Input n)
{
    CheckLoseLife();
    switch (n) {
//        case Input::Up:
//            _player.up();
//            std::cout << "jump" << std::endl;
//            return false;
        case Input::Left:
            _player.left();
            std::cout << "left" << std::endl;
            return false;
        case Input::Right:
            _player.right();
            std::cout << "right" << std::endl;
            return false;
//        case Input::Down:
//            _player.down();
//            std::cout << "down" << std::endl;
//            return false;
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
//    for (auto &e: _bat) {
//        e.draw(win);
//    }
    _player.draw(win);
//    for (auto &e: _life) {
//        e.draw(win);
//    }

    for (auto &e : _layer)
        e.draw(win);
    _music.playSound("dbz", "assets/music_dbz.ogg");
    _music.setLoop("dbz");
    win.draw(_score);
    if (_bossBattle) {
        _panel.draw(win);
        _panel.write(win);
    }
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