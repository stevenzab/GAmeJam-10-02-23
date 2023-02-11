/*
** EPITECH PROJECT, 2023
** GAmeJam-10-02-23
** File description:
** Player
*/

#ifndef BAT_HPP_
#define BAT_HPP_

#include "Sprite.hpp"

class Bat : public Sprite {
    public:
        Bat();
        ~Bat();
        void update();
        void moveRect();

    protected:
    private:
        int count_frame;
        int changeX;
        int changeY;
};

#endif /* !PLAYER_HPP_ */
