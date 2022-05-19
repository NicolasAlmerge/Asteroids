// Space class declaration

#pragma once
#include "SpaceElement.hpp"
#include "vector"
#include "memory"


class Space {
    std::vector<std::unique_ptr<SpaceElement>> elements;
    std::vector<std::unique_ptr<SpaceElement>> toAdd;
    sf::Clock clock;
    bool toFree = false;
    bool asteroids = true;

public:
    void add(std::unique_ptr<SpaceElement>);
    void refresh();
    void testCollisions();
    void display(sf::RenderWindow&) const;
    void clear();
    void free();
    inline bool isEmpty() const {return elements.empty();};
    inline bool noAsteroids() const {return !asteroids;}
};
