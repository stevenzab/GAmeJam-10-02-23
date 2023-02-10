/*
** EPITECH PROJECT, 2023
** GAmeJam-10-02-23
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <SFML/Graphics.hpp>

class Sprite {
    public:
        Sprite();
        ~Sprite();
        void Init_sprite();

    protected:
    private:
        sf::IntRect _rect;
        sf::Texture texture;
        sf::Sprite sprite;
};

#endif /* !SPRITE_HPP_ */
