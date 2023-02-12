/*
** EPITECH PROJECT, 2023
** jam1
** File description:
** Panel
*/

#ifndef PANEL_HPP_
#define PANEL_HPP_

#include "Sprite.hpp"

class Panel : public Sprite {
    public:
        Panel();
        ~Panel();

        void write(Window &win);
        void setFontAllocator(std::shared_ptr<ResourceAllocator<sf::Font>> font);

    protected:
    private:
        std::shared_ptr<ResourceAllocator<sf::Font>> _font;
        sf::Text _name;
        sf::Text _text;
        sf::Text _text1;
        Sprite _juan;
};

#endif /* !PANEL_HPP_ */
