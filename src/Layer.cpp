/*
** EPITECH PROJECT, 2023
** jam1
** File description:
** Layer
*/

#include "../include/Layer.hpp"
#include <iostream>

Layer::Layer(int num) : _layer_num(num)
{
    srand(time(NULL) * _layer_num);
    int w = rand() % 10;
    _hole = std::make_pair(w * 102.4, (w + 1) * 102.4);
    for (int i = 0; i != 10; i++) {
        if (i == w) {
            _layer.push_back(0);
        } else
            _layer.push_back(1);
    }
    for (int i = 0; i != 10; i++)
        _plateform.push_back(Sprite(i * 102.4, _layer_num * 300 + 500));
        _y = _layer_num * 300 + 500 - 80;
}

Layer::~Layer()
{
}

void Layer::draw(Window &win) {
    for (auto &e : _plateform)
        e.draw(win);
}

void Layer::setTextureAllocator(std::shared_ptr<ResourceAllocator<sf::Texture>> allocator)
{
    _alloc = allocator;
    for (int i = 0; i != _layer.size(); i++) {
        _plateform[i].setSpriteScale(0.8, 0.8);
        _plateform[i].setTextureAllocator(_alloc);
        _plateform[i].load("platformMid");
        if (_layer[i + 1] == 0 && i + 1 != _layer.size())
            _plateform[i].load("platformRight");
        if (_layer[i - 1] == 0 && i - 1 != -1)
            _plateform[i].load("platformLeft");
        if (_layer[i] == 0)
            _plateform[i].load("void");
    }
}

void Layer::update()
{
    _y -= 5;
    for (auto &e : _plateform)
        e.changePosition(e.getX(), e.getY() - 5);
}

int Layer::getLayerNum() const
{
    return _layer_num;
}

int Layer::getLayerY() const
{
    return _y;
}

std::pair<double, double> Layer::getHole() const
{
    return _hole;
}