/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-flavien.thel
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include "EInput.hpp"
#include "Window.hpp"

class IScene {
    public:
        virtual ~IScene() = default;

        virtual void update() = 0;
        virtual bool eventManager(Input n) = 0;
        virtual sf::View getView() const = 0;
        virtual void setMouseClick(const std::pair<double, double> &vec) = 0;
        virtual void draw(Window &win) = 0;
    protected:
    private:
};

#endif /* !ISCENE_HPP_ */
