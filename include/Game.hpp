
#ifndef GAME_HPP_
#define GAME_HPP_

#include "IScene.hpp"

class Game : public IScene {
    public:
        Game(std::shared_ptr<ResourceAllocator<sf::Texture>> alloc, std::shared_ptr<ResourceAllocator<sf::Font>> font);
        ~Game();

        void update();
        void eventManager(Input n);
        sf::View getView() const;
        void setMouseClick(const std::pair<double, double> &vec);
        void draw(Window &win);

    protected:
    private:
};

#endif /* !GAME_HPP_ */
