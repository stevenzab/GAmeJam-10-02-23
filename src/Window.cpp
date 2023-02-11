#include "../include/Window.hpp"

Window::Window()
{
    _height = 1920;
    _width = 1080;
    _win.create(sf::VideoMode(_width, _height), "JumpGoku", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
    _win.setFramerateLimit(60);
    _status = true;
}

Window::~Window()
{
    _win.close();
}

bool Window::isOpen() const
{
    return _status;
}

void Window::clear(int r, int g, int b)
{
    _win.clear(sf::Color(r, g, b));
}

void Window::display()
{
    _win.display();
}

Input Window::manageEvent()
{
    while (_win.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _status = false;
            return Esc;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            _status = false;
            return Esc;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            return MouseLeft;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            return Up;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            return Down;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            return Left;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            return Right;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            return Space;
    }
    return Nope;
}

std::pair<double, double> Window::getMousePosition() const
{
    sf::Vector2f n = _win.mapPixelToCoords(sf::Mouse::getPosition());
    return std::make_pair<double, double>(n.x, n.y);
}

int Window::getHeight() const
{
    return _height;
}

int Window::getWidth() const
{
    return _width;
}

void Window::draw(const sf::Drawable &elem)
{
    _win.draw(elem);
}

void Window::setView(const sf::View &view)
{
    _win.setView(view);
}
