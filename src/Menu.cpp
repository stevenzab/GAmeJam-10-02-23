/*
** EPITECH PROJECT, 2023
** jam1
** File description:
** Menu
*/

#include "../include/Menu.hpp"

Menu::Menu(std::shared_ptr<ResourceAllocator<sf::Texture>> alloc, std::shared_ptr<ResourceAllocator<sf::Font>> font) : _alloc(alloc), _font(font), _play(835.25, 800), _background(), _music(), _sound()
{
    sf::Vector2f view_center = {1920 / 2, 1080 / 2};
    _view_size = {960.0, 540.0};
    _view.setCenter(view_center);
    _view.setSize(_view_size);
    _view.zoom(2);
    std::shared_ptr<sf::Font> text = _font->Get("DungeonFont");
    _background.setTextureAllocator(_alloc);
    _background.load("assets/background.png");
    _text.setString("JumpGoku");
    _text.setFont(*text);
    _text.setCharacterSize(160);
    _text.setPosition(650, 30);
    _text.setFillColor(sf::Color::Black);
    _play.setTextureAllocator(_alloc);
    _play.load("Play");
    _music.loadSound("skfk", "assets/shukufuku.ogg");
}

Menu::~Menu()
{
    _music.stopSound("shfk", "assets/shukufuku.ogg");
}

void Menu::update()
{
    // update Position
}

bool Menu::eventManager(Input n)
{
    switch (n) {
        case MouseLeft:
            return _play.isClicked(_click);
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
    _background.draw(win);
    _music.playSound("skfk", "assets/shukufuku.ogg");
    _music.setLoop("skfk");
    _play.draw(win);
    win.draw(_text);
//    for (auto &e : _sprites)
//        e.draw(win);
    //draw stuff ob window
}
