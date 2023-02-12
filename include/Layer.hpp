/*
** EPITECH PROJECT, 2023
** jam1
** File description:
** Layer
*/

#ifndef LAYER_HPP_
#define LAYER_HPP_

#include <vector>
#include "Sprite.hpp"

class Layer {
    public:
        Layer(int num);
        ~Layer();

        void draw(Window &win);
        void setTextureAllocator(std::shared_ptr<ResourceAllocator<sf::Texture>> allocator);

    protected:
    private:
        int _layer_num;
        std::vector<int> _layer;
        std::vector<Sprite> _plateform;
        std::shared_ptr<ResourceAllocator<sf::Texture>> _alloc;
};

#endif /* !LAYER_HPP_ */
