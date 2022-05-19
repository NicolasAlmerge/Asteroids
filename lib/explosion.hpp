// Explosion class declaration

#pragma once
#include "SpaceElement.hpp"
#include "coordinates.hpp"


class Explosion: public SpaceElement {
    sf::Sound sound;
    float age = 0.f;

public:
    explicit Explosion(const Coordinates&);
    virtual void reactCollision(ElementType) override {}

    static constexpr float LIFESPAN = 0.1f;

protected:
    virtual void update(float) override;
};
