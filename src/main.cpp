// Asteroids Project

#include "../lib/space.hpp"
#include "../lib/game.hpp"
using namespace sf;


constexpr unsigned int WIDTH = 1920;
constexpr unsigned int HEIGHT = 1200;
constexpr unsigned int FRAMERATE_LIMIT = 60;
constexpr bool MOUSE_CURSOR_VISIBLE = true;


const std::string TEXTURES[] {
    "asteroid.png", "background.png", "explosion.png", "missile.png", "ship.png"
};

const std::string SOUNDBUFFERS[] {"explosion.wav", "laser.wav"};


int main() {
    // Create new window
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Asteroids", Style::Titlebar | Style::Close);
    window.setFramerateLimit(FRAMERATE_LIMIT);
    window.setMouseCursorVisible(MOUSE_CURSOR_VISIBLE);

    // Set icon image
    Image icon;
    if (icon.loadFromFile(RESOURCE_PATH + std::string("asteroid.png"))) {
        Vector2u size = icon.getSize();
        window.setIcon(size.x, size.y, icon.getPixelsPtr());
    } else
        std::cerr << "Image 'asteroid.png' could not be loaded!" << std::endl;

    // Create new entities
    Coordinates::setSpaceLimits(WIDTH, HEIGHT);
    Space space;
    Game game(space);

    // Load resources
    for (std::string t: TEXTURES) ResourceManager<Texture>::loadResource(t);
    for (std::string t: SOUNDBUFFERS) ResourceManager<SoundBuffer>::loadResource(t);

    // Load background
    Sprite background;
    background.setTexture(ResourceManager<Texture>::getResource("background.png"));

    // While window is open
    while (window.isOpen()) {
        try {
            Event event;

            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();
                else if (event.type == Event::KeyPressed && !game.isRunning())
                    game.start();
            }

            space.refresh();
            space.testCollisions();

            window.clear();
            if (game.isRunning() || !space.isEmpty()) window.draw(background);
            space.display(window);
            game.display(window);
            window.display();

            space.clear();
            if (game.isRunning() && space.noAsteroids()) game.end();

        } catch (const std::exception& exception) {
            game.initializeException(exception);
        }
    }

    // Return 0 upon success
    return 0;
}
