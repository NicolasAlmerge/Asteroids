// Space element class declaration

#pragma once
#include "array"
#include "iostream"
#include "memory"
#include "SFML/Graphics.hpp"
#include "ResourceManager.hpp"
#include "vector.hpp"
#include "coordinates.hpp"


enum class ElementType {SHIP, ASTEROID, BULLET, OTHER};


struct SpaceElement {
    explicit SpaceElement(const std::string&);
    SpaceElement(const SpaceElement&) = delete;
    void operator =(const SpaceElement&) = delete;
    virtual ~SpaceElement() = default;

    void refresh(float);
    float getRadius() const;
    void testCollision(SpaceElement&);

    inline ElementType getType() const { return type; }

    virtual void display(sf::RenderWindow&) const;
    virtual void reactCollision(ElementType) = 0;

    static inline bool isDestructed(std::unique_ptr<SpaceElement> &element) {return element->destructed;}
    static constexpr float RADIUS_DIMINISHING_FACTOR = 2.4f;

protected:
    bool destructed = false;
    ElementType type = ElementType::OTHER;
    sf::Sprite sprite;
    Coordinates position;
    Vector speed;
    float angularSpeed = 0.f;

    virtual void update(float) {}
};
