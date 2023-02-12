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
        void up();
        void left();
        void right();
        void down();
        void setFloor(int floor, int y);
        int getFloor() const;

    protected:
    private:
        int count_frame;
        int changeX;
        int changeY;
        int _floor;
};

#endif /* !PLAYER_HPP_ */
