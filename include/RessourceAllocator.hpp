#ifndef RESSOURCEALLOCATOR_HPP_
#define RESSOURCEALLOCATOR_HPP_

#include <map>
#include <memory>
#include <iostream>
#include "Error.hpp"

template <typename T>
class ResourceAllocator {
    public:
        ResourceAllocator() {
            currentId = 0;
        };
        ~ResourceAllocator() {};
        int Add(const std::string &filePath) {
            if (resources.size() != 0) {
                auto it = resources.find(filePath);
                if (it != resources.end())
                    return it->second.first;
            }
            std::shared_ptr<T> resource = std::make_shared<T>();
            if (!resource->loadFromFile(filePath))
                throw GraphicalError("GraphicalError couldn't load file");
            resources.insert(std::make_pair(filePath, std::make_pair(currentId, resource)));
            return currentId++;
        };

        void Remove(int id) {
            if (resources.size() == 0)
                return;
            for (auto it = resources.begin(); it != resources.end(); it++)
                if (it->second.first == id)
                    resources.erase(it->first);
        };

        std::shared_ptr<T> Get(const std::string &e) {
            if (resources.size() == 0)
                return nullptr;
            for (auto it = resources.begin(); it != resources.end(); it++)
                if (it->first.find(e) != std::string::npos)
                    return it->second.second;
            return nullptr;
        };

        std::shared_ptr<T> Get(int id) {
            for (auto it = resources.begin(); it != resources.end(); ++it)
                if (it->second.first == id)
                    return it->second.second;
            return nullptr;
        };

        bool Has(int id) {
            return (Get(id) != nullptr);
        };

    private:
        int currentId;
        std::map<std::string, std::pair<int, std::shared_ptr<T>>> resources;
};

#endif /* !RESSOURCEALLOCATOR_HPP_ */
