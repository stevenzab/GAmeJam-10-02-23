/*
** EPITECH PROJECT, 2023
** jam1
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "Sprite.hpp"

class Button : public Sprite {
    public:
        Button(int x, int y);
        ~Button();

        bool isClicked(std::pair<double, double> &clicked);

    protected:
    private:

};

#endif /* !BUTTON_HPP_ */

