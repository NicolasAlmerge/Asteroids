// Bullet class definition

#include "../lib/bullet.hpp"


Bullet::Bullet(const Coordinates& p_position, float rotation): SpaceElement("missile.png") {
    type = ElementType::BULLET;
    position = p_position;
    sprite.setRotation(rotation);
    speed = Vector::fromSizeAndAngle(SPEED, rotation);
    sound.setBuffer(ResourceManager<sf::SoundBuffer>::getResource("laser.wav"));
    sound.play();
}

void Bullet::reactCollision(ElementType other) {
    if (other != ElementType::SHIP)
        destructed = true;
}
