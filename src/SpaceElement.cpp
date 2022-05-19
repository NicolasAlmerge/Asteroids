// Space element class definition

#include "../lib/SpaceElement.hpp"


SpaceElement::SpaceElement(const std::string& filePath) {
    sprite.setTexture(ResourceManager<sf::Texture>::getResource(filePath));
    sf::FloatRect localBounds = sprite.getLocalBounds();
    sprite.setOrigin(localBounds.width / 2, localBounds.height / 2);
    sprite.setPosition(position.getX(), position.getY());
}

void SpaceElement::refresh(float time) {
    update(time);
    Vector mvt = speed * time;
    position += mvt;
    sprite.setPosition(position.getX(), position.getY());
    sprite.rotate(angularSpeed * time);
}

void SpaceElement::display(sf::RenderWindow& window) const {
    std::array<Vector, 9> visuals{
        Vector{-1, -1}, Vector{0, -1}, Vector{1, -1},
        Vector{-1, 0}, Vector{0, 0}, Vector{1, 0},
        Vector{-1, 1}, Vector{0, 1}, Vector{1, 1}
    };

    for (Vector& visual: visuals) {
        sf::Transform transformation;
        transformation.translate(visual.getX() * Coordinates::getSpaceLength(), visual.getY() * Coordinates::getSpaceHeight());
        window.draw(sprite, transformation);
    }
}

float SpaceElement::getRadius() const {
    return sprite.getGlobalBounds().height / RADIUS_DIMINISHING_FACTOR;
}

void SpaceElement::testCollision(SpaceElement& other) {
    float distance = position.getDistanceTo(other.position);
    if (distance < getRadius() + other.getRadius())
        reactCollision(other.type);
}
