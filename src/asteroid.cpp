// Asteroid class definition

#include "../lib/asteroid.hpp"
#include "../lib/explosion.hpp"
#include "random"

typedef std::uniform_real_distribution<float> real_distr;


Asteroid::Asteroid(Game& p_game, Space& p_space, Asteroid* parent): SpaceElement("asteroid.png"), game(p_game), space(p_space) {
    type = ElementType::ASTEROID;

    std::random_device generator;
    real_distr xPosDistribution(0, Coordinates::getSpaceLength());
    real_distr yPosDistribution(0, Coordinates::getSpaceHeight());
    real_distr speedDistribution(80, 150);
    real_distr angleDistribution(0, 360);

    speed = Vector::fromSizeAndAngle(speedDistribution(generator), angleDistribution(generator));
    angularSpeed = angleDistribution(generator);

    if (parent) {
        sf::Vector2f parentScale = parent->sprite.getScale();
        sprite.setScale(parentScale.x / DIMINISHING_FACTOR, parentScale.y / DIMINISHING_FACTOR);
        position.setX(parent->position.getX());
        position.setY(parent->position.getY());
    } else {
        position.setX(xPosDistribution(generator));
        position.setY(yPosDistribution(generator));
    }
}

void Asteroid::reactCollision(ElementType other) {
    if (other == ElementType::BULLET) {
        destructed = true;
        game.addPoints(sprite.getScale().x * 100);
        if (sprite.getScale().x > MINIMUM_SIZE) {
            space.add(std::make_unique<Asteroid>(game, space, this));
            space.add(std::make_unique<Asteroid>(game, space, this));
        }
        space.add(std::make_unique<Explosion>(position));
    }
}
