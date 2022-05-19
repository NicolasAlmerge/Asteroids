// Asteroid class declaration

#pragma once
#include "SpaceElement.hpp"
#include "space.hpp"
#include "game.hpp"


class Asteroid: public SpaceElement {
    Game& game;
    Space& space;

public:
    explicit Asteroid(Game&, Space&, Asteroid* parent = nullptr);
    virtual void reactCollision(ElementType) override;
    
    static constexpr float DIMINISHING_FACTOR = 1.4f;
    static constexpr float MINIMUM_SIZE = 0.2f;
};
