/*
** EPITECH PROJECT, 2023
** GAmeJam-10-02-23
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Sprite.hpp"

class Player : public Sprite {
    public:
        Player();
        ~Player();
        void update();
        void moveRect();

    protected:
    private:
        int count_frame;
};

#endif /* !PLAYER_HPP_ */
