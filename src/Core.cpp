#include "../include/Core.hpp"
#include <iostream>

Core::Core() : _win()
{
    findPath();
    _font = std::make_shared<ResourceAllocator<sf::Font>>();
    _alloc = std::make_shared<ResourceAllocator<sf::Texture>>();
    loadRessources();
    _m_chan = std::make_unique<SceneManager>();
    _m_chan->addScene(std::make_shared<Game>(_alloc, _font));
    _m_chan->addScene(std::make_shared<Menu>(_alloc, _font));
}

Core::~Core()
{
}

void Core::loadRessources()
{
    _alloc->Add("assets/goku.png");
    _alloc->Add("assets/Play.png");
    _alloc->Add("assets/background.png");
    _alloc->Add("assets/Gbackground.png");
    _alloc->Add("assets/bat.png");
    _alloc->Add("assets/LIFE1.png");
    _alloc->Add("assets/LIFE0.png");
    _alloc->Add("assets/platformLeft.png");
    _alloc->Add("assets/platformRight.png");
    _alloc->Add("assets/platformMid.png");
    _alloc->Add("assets/void.png");
    _alloc->Add("assets/panel.png");
    _alloc->Add("assets/Wizard_idle.png");
    _alloc->Add("assets/goku_kameha.png");
    _font->Add("assets/DungeonFont.ttf");
}

void Core::loop()
{
    _win.setView(_m_chan->getView());
    while (_win.isOpen()) {
        _m_chan->manageEvent(_win.manageEvent());
        _m_chan->setMousePos(_win.getMousePosition());
        _win.clear();
        _m_chan->update();
        _m_chan->draw(_win);
        _win.setView(_m_chan->getView());
        _win.display();
    }
}

void Core::findPath()
{
    for (const auto &entry : std::filesystem::recursive_directory_iterator(".")) {
        std::string line(entry.path());
        if (line.find(".ttf") != std::string::npos) {
            for (int i = line.size(); i != -1; i--)
                if (line[i] == '/') {
                    line.erase(line.begin() + i + 1, line.end());
                    _path_prefix = line;
                    return;
                }
        }
    }
}

