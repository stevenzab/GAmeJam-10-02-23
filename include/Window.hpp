
#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "EInput.hpp"

class Window
{
    public:
        Window();
        ~Window();

        void draw(const sf::Drawable &elem);
        void setView(const sf::View &view);

        bool isOpen() const;
        void clear(int r = 0, int g = 0, int b = 0);
        void display();
        std::pair<double, double> getMousePosition() const;
        Input manageEvent();

        int getHeight() const;
        int getWidth() const;

    protected:
    private:
        bool _status;

        int _height;
        int _width;

        sf::Event _event;
        sf::RenderWindow _win;
};

#endif /* !WINDOW_HPP_ */
