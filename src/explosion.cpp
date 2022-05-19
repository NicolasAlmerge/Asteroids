// Explosion class definition

#include "../lib/explosion.hpp"


Explosion::Explosion(Coordinates const &p_position): SpaceElement("explosion.png") {
    position = p_position;
    sound.setBuffer(ResourceManager<sf::SoundBuffer>::getResource("explosion.wav"));
    sound.play();
}

void Explosion::update(float time) {
    age += time;

    if (age < LIFESPAN) {
        float scale = age / LIFESPAN;
        sprite.setScale(scale, scale);
    } else {
        sprite.setScale(0.f, 0.f);
        if (sound.getStatus() == sf::SoundSource::Stopped)
            destructed = true;
    }
}
