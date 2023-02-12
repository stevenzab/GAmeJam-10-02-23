
#ifndef GAME_HPP_
#define GAME_HPP_

#include <memory>
#include <chrono>
#include "IScene.hpp"
#include "RessourceAllocator.hpp"
#include "Player.hpp"
#include "Music.hpp"
#include "Sound.hpp"
#include "Background.hpp"
#include "bat.hpp"
#include "Life.hpp"
#include "Layer.hpp"
#include "Panel.hpp"

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
        void CheckLoseLife();

    protected:
    private:
        std::vector<Bat> _bat;
        std::vector<Life> _life;
        std::vector<Layer> _layer;
        Player _player;
        Background _background;
        sf::View _view;
        std::pair<double, double> _click;
        std::shared_ptr<ResourceAllocator<sf::Texture>> _alloc;
        std::shared_ptr<ResourceAllocator<sf::Font>> _font;
        Music _music;
        Sound _sound;
        sf::Text _score;
        bool _ispause;
        int _health;
        int stackHealth;
        bool _bossBattle;
        Panel _panel;
        int _space;
        sf::Text _spam;
        std::chrono::time_point<std::chrono::steady_clock> _start;
};

#endif /* !GAME_HPP_ */
