/*
** EPITECH PROJECT, 2023
** GAmeJam-10-02-23
** File description:
** WIndow
*/

#include "../Include/Window.hpp"

Window::Window()
{
}

Window::~Window()
{
}

void Window::Init_window()
{
    Sprite sprite;
    Background background;
    window.create(sf::VideoMode(1920, 1080), "My window");
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
                background.Init_background();
                sprite.Init_sprite();
        }
        window.clear();
        window.display();
    }
}