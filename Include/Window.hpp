/*
** EPITECH PROJECT, 2023
** GAmeJam-10-02-23
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <SFML/Graphics.hpp>

class Window {
    public:
        Window();
        ~Window();
        void Init_window();
    protected:
    private:
        sf::RenderWindow window;

};

#endif /* !WINDOW_HPP_ */
