// Resource manager class declaration

#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "iostream"
#include "unordered_map"
#include "UnknownResource.hpp"


const std::string RESOURCE_PATH = "./assets/";


template <typename T>
class ResourceManager {
    static std::unordered_map<std::string, T> resources;

public:
    ResourceManager() = delete;

    inline static void loadResource(const std::string& filePath) {
        if (!resources[filePath].loadFromFile(RESOURCE_PATH + filePath))
            throw UnknownResource(filePath);
    }

    inline static const T& getResource(const std::string& filePath) {
        auto result = resources.find(filePath);

        if (result == std::end(resources)) {
            if (!resources[filePath].loadFromFile(RESOURCE_PATH + filePath))
                throw UnknownResource(filePath);
            return resources[filePath];
        }

        return result->second;
    }
};

template<>
std::unordered_map<std::string, sf::Texture> ResourceManager<sf::Texture>::resources;

template<>
std::unordered_map<std::string, sf::SoundBuffer> ResourceManager<sf::SoundBuffer>::resources;
