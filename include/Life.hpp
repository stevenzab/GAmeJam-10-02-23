/*
** EPITECH PROJECT, 2023
** GAmeJam-10-02-23
** File description:
** Life
*/

#ifndef LIFE_HPP_
#define LIFE_HPP_

#include "Sprite.hpp"

class Life : public Sprite {
    public:
        Life(int x, int y);
        ~Life();

        int GetHealth();
        void LoseLife();
    protected:
    private:
        int _health;
};

#endif /* !LIFE_HPP_ */
