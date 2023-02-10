
#ifndef MENU_HPP_
#define MENU_HPP_

#include <memory>
#include "IScene.hpp"
#include "RessourceAllocator.hpp"

class Menu : public IScene {
    public:
        Menu(std::shared_ptr<ResourceAllocator<sf::Texture>> alloc, std::shared_ptr<ResourceAllocator<sf::Font>> font);
        ~Menu();

        void update();
        void eventManager(Input n);
        sf::View getView() const;
        void setMouseClick(const std::pair<double, double> &vec);
        void draw(Window &win);
    protected:
    private:
};

#endif /* !MENU_HPP_ */
