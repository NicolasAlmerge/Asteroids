// Ship class declaration

#pragma once
#include "SpaceElement.hpp"
#include "explosion.hpp"
#include "space.hpp"
#include "game.hpp"


class Ship: public SpaceElement {
    bool accelerating = false;
    bool turningLeft = false;
    bool turningRight = false;
    Game& game;
    Space& space;
    sf::Clock lastBullet;

    void pollEvent();

public:
    explicit Ship(Game&, Space&, const sf::Color&);
    virtual void reactCollision(ElementType) override;

    static constexpr float ACCELERATION = 7000.f;
    static constexpr float FRICTION_COEFF = 5.f;
    static constexpr float ANGULAR_ACCELERATION = 200.f;
    static constexpr float BULLET_COOLDOWN = 0.1f;

protected:
    virtual void update(float) override;    
};
