// Ship class definition

#include "../lib/ship.hpp"
#include "../lib/bullet.hpp"


Ship::Ship(Game& p_game, Space& p_space, const sf::Color& color): SpaceElement("ship.png"), game(p_game), space(p_space) {
    type = ElementType::SHIP;
    sprite.setColor(color);
    sprite.rotate(-90);
}

void Ship::pollEvent() {
    accelerating = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    turningLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    turningRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && lastBullet.getElapsedTime().asSeconds() > BULLET_COOLDOWN) {
        space.add(std::make_unique<Bullet>(position, sprite.getRotation()));
        lastBullet.restart();
    }
}

void Ship::update(float time) {
    pollEvent();
    if (!destructed) {
        if (accelerating)
            speed += Vector::fromSizeAndAngle(ACCELERATION * time, sprite.getRotation());
        speed -= speed * FRICTION_COEFF * time;

        if (turningLeft) angularSpeed = -ANGULAR_ACCELERATION;
        else if (turningRight) angularSpeed = ANGULAR_ACCELERATION;
        else angularSpeed = 0.f;
    }
}

void Ship::reactCollision(ElementType other) {
    if (other == ElementType::ASTEROID) {
        destructed = true;
        game.end();
        space.add(std::make_unique<Explosion>(position));
    }
}
