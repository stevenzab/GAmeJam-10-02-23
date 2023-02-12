
#ifndef GAME_HPP_
#define GAME_HPP_

#include <memory>
#include "IScene.hpp"
#include "RessourceAllocator.hpp"
#include "Player.hpp"
#include "Music.hpp"
#include "Sound.hpp"
#include "Background.hpp"
#include "bat.hpp"
#include "Life.hpp"

class Game : public IScene {
    public:
        Game(std::shared_ptr<ResourceAllocator<sf::Texture>> alloc, std::shared_ptr<ResourceAllocator<sf::Font>> font);
        ~Game();

        void update();
        bool eventManager(Input n);
        sf::View getView() const;
        void setMouseClick(const std::pair<double, double> &vec);
        void draw(Window &win);
        void CreateBat();
        void LooseLife();

    protected:
    private:
        std::vector<Bat> _bat;
        std::vector<Life> _life;
        Player _player;
        Background _background;
        sf::View _view;
        std::pair<double, double> _click;
        std::shared_ptr<ResourceAllocator<sf::Texture>> _alloc;
        std::shared_ptr<ResourceAllocator<sf::Font>> _font;
        Music _music;
        Sound _sound;
        bool _ispause;
        int _health;
        int stackHealth;
};

#endif /* !GAME_HPP_ */
