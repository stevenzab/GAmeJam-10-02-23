
#ifndef CORE_HPP_
#define CORE_HPP_

#include <memory>
#include <filesystem>
#include <string>
#include "RessourceAllocator.hpp"
#include "SceneManager.hpp"
#include "Window.hpp"

class Core {
    public:
        Core();
        ~Core();

        void loop();
    protected:
    private:
        void loadRessources();
        void findPath();

        std::string _path_prefix;
        std::shared_ptr<ResourceAllocator<sf::Texture>> _alloc;
        std::shared_ptr<ResourceAllocator<sf::Font>> _font;
        std::unique_ptr<SceneManager> _m_chan;
        Window _win;
};

#endif /* !CORE_HPP_ */
