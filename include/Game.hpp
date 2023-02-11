
#ifndef GAME_HPP_
#define GAME_HPP_

#include <memory>
#include "IScene.hpp"
#include "RessourceAllocator.hpp"
#include "Player.hpp"

class Game : public IScene {
    public:
        Game(std::shared_ptr<ResourceAllocator<sf::Texture>> alloc, std::shared_ptr<ResourceAllocator<sf::Font>> font);
        ~Game();

        void update();
        bool eventManager(Input n);
        sf::View getView() const;
        void setMouseClick(const std::pair<double, double> &vec);
        void draw(Window &win);

    protected:
    private:
        Player _player;
        sf::View _view;
        std::pair<double, double> _click;
};

#endif /* !GAME_HPP_ */
