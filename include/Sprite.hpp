/*
** EPITECH PROJECT, 2023
** GAmeJam-10-02-23
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <SFML/Graphics.hpp>
#include "RessourceAllocator.hpp"
#include "Window.hpp"


class Sprite {
    public:
        Sprite(double x, double y);
        ~Sprite();

        void setSpriteScale(double x, double y);
        void setSpritePosition(double x, double y);
        void setSpriteRect(double left, double height, double width);
        void changePosition(double x, double y);

        void draw(Window &win) const;
        sf::RectangleShape getShape() const {
            return shape;
        }
        void load(int id);
        void load(const std::string &e);
        void setTextureAllocator(std::shared_ptr<ResourceAllocator<sf::Texture>> allocator);
        double getX() const;
        double getY() const;

    protected:
        std::shared_ptr<ResourceAllocator<sf::Texture>> _alloc;
        sf::Sprite _sprite;
        sf::RectangleShape shape;
        double _x;
        double _y;
    private:
};

#endif /* !SPRITE_HPP_ */
