#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include <stack>
#include <memory>
#include "IScene.hpp"
#include "Window.hpp"

class SceneManager {
    public:
        SceneManager();
        ~SceneManager();

        void addScene(std::shared_ptr<IScene> scene);
        void switchScene();

        void manageEvent(Input i);
        sf::View getView() const;

        void processInput(const std::string &e);
        void update();
        void draw(Window &win);
        void setMousePos(const std::pair<double, double> &vec);
    protected:
    private:
        std::stack<std::shared_ptr<IScene>> _scenes;
        unsigned int _cur;
};

#endif /* !SCENEMANAGER_HPP_ */
