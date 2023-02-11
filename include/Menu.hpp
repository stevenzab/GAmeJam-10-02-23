
#ifndef MENU_HPP_
#define MENU_HPP_

#include <memory>
#include "IScene.hpp"
#include "RessourceAllocator.hpp"
#include "Button.hpp"
#include "Music.hpp"
#include "Sound.hpp"

class Menu : public IScene {
    public:
        Menu(std::shared_ptr<ResourceAllocator<sf::Texture>> alloc, std::shared_ptr<ResourceAllocator<sf::Font>> font);
        ~Menu();

        void update();
        bool eventManager(Input n);
        sf::View getView() const;
        void setMouseClick(const std::pair<double, double> &vec);
        void draw(Window &win);
    protected:
    private:
        sf::View _view;
        std::pair<double, double> _click;
        std::shared_ptr<ResourceAllocator<sf::Texture>> _alloc;
        std::shared_ptr<ResourceAllocator<sf::Font>> _font;
        std::vector<Sprite> _sprites;
        sf::Text _text;
        sf::Vector2f _view_size;
        Button _play;
        Music _music;
        Sound _sound;
};

#endif /* !MENU_HPP_ */
