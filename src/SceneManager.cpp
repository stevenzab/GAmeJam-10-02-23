/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-flavien.thel
** File description:
** SceneManager
*/

#include "../include/SceneManager.hpp"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::addScene(std::shared_ptr<IScene> scene)
{
    _scenes.push(scene);
}

void SceneManager::switchScene()
{
    _scenes.pop();
}

void SceneManager::processInput(const std::string &e)
{
    if (_scenes.size() != 0)
        _scenes.top()->parseServerInput(e);
}

void SceneManager::update()
{
    if (_scenes.size() != 0)
        _scenes.top()->update();
}

void SceneManager::draw(Window &win)
{
    if (_scenes.size() != 0)
        _scenes.top()->draw(win);
}

void SceneManager::setMousePos(const std::pair<double, double> &vec)
{
    _scenes.top()->setMouseClick(vec);
}

void SceneManager::manageEvent(Input i)
{
    _scenes.top()->eventManager(i);
}

sf::View SceneManager::getView() const
{
    return _scenes.top()->getView();
}