// Bullet class declaration

#pragma once
#include "SpaceElement.hpp"
#include "SFML/Audio.hpp"


class Bullet: public SpaceElement {
    sf::Sound sound;

public:
    explicit Bullet(const Coordinates&, float);
    virtual void reactCollision(ElementType) override;

    static constexpr float SPEED = 2000.f;
};
