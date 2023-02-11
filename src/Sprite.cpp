#include "../include/Sprite.hpp"

Sprite::Sprite(double x, double y) : _x(x), _y(y)
{
    _sprite.setPosition(_x, _y);
}

Sprite::~Sprite()
{
}

void Sprite::setSpriteScale(double x, double y)
{
    _sprite.setScale(x, y);
}

void Sprite::setSpritePosition(double x, double y)
{
}

void Sprite::changePosition(double x, double y)
{
    _x = x;
    _y = y;
    _sprite.setPosition(_x, _y);
}

void Sprite::setSpriteRect(double left, double height, double width)
{
    _sprite.setTextureRect(sf::IntRect(left, 0, height, width));
}

double Sprite::getX() const
{
    return _x;
}

double Sprite::getY() const
{
    return _y;
}

void Sprite::draw(Window &win) const
{
    win.draw(_sprite);
}

void Sprite::load(int id)
{
    if (_alloc == nullptr || id < 0)
        return;
    std::shared_ptr<sf::Texture> text = _alloc->Get(id);
    if (text != nullptr) {
        _sprite.setTexture(*text);
    }
}

void Sprite::load(const std::string &e)
{
    if (_alloc == nullptr)
        return;
    std::shared_ptr<sf::Texture> text = _alloc->Get(e);
    if (text != nullptr) {
        _sprite.setTexture(*text);
    }
}

void Sprite::setTextureAllocator(std::shared_ptr<ResourceAllocator<sf::Texture>> allocator)
{
    _alloc = allocator;
}