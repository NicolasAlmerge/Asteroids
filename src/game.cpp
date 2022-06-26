// Game class definition

#include "../lib/game.hpp"
#include "../lib/ship.hpp"
#include "../lib/asteroid.hpp"
#include "../lib/font.hpp"
#include "string"
#include "fstream"
using namespace std::string_literals;

const sf::Color SHIP_COLOR(128, 255, 128);


Game::Game(Space& p_space): space(p_space) {
    if (!font.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size))
        throw std::runtime_error("Cannot find Air Americana font!");

    textScore.setFont(font);
    textScore.setCharacterSize(44);
    textScore.move(10, 45);

    textBestScore.setFont(font);
    textBestScore.setCharacterSize(44);
    textBestScore.move(10, 0);

    welcomeText.setFont(font);
    welcomeText.setCharacterSize(120);
    welcomeText.setString("PRESS ANY KEY TO START");
    welcomeText.move(450, 500);

    std::ifstream file(RESOURCE_PATH + std::string("best_score.txt"));
    if (file.is_open()) file >> bestScore;
    file.close();

    refreshBestScore();
}

void Game::start() {
    running = true;
    score = 0;
    refreshText();
    space.add(std::make_unique<Ship>(*this, space, SHIP_COLOR));
    space.add(std::make_unique<Asteroid>(*this, space));
    space.add(std::make_unique<Asteroid>(*this, space));
    space.add(std::make_unique<Asteroid>(*this, space));
}

void Game::addPoints(unsigned int points) {
    score += points;
    refreshText();
}

void Game::end() {
    running = false;
    if (score > bestScore) {
        bestScore = score;
        refreshBestScore();
        std::ofstream file(RESOURCE_PATH + std::string("best_score.txt"));
        if (file.is_open()) file << bestScore;
        else throw std::runtime_error("Cannot open 'best_score.txt' in write-only mode!");
        file.close();
    }
    space.free();
}

void Game::display(sf::RenderWindow& window) const {
    if (exceptionText)
        window.draw(*exceptionText);
    else {
        if (!running && space.isEmpty()) window.draw(welcomeText);
        else window.draw(textScore);
        window.draw(textBestScore);
    }
}

void Game::initializeException(const std::exception& exception) {
    exceptionText = std::make_unique<sf::Text>();
    exceptionText->setFont(font);
    exceptionText->setString(exception.what());
    exceptionText->setFillColor(sf::Color::Red);
}

void Game::refreshText() {
    textScore.setString("Score: " + std::to_string(score));
}

void Game::refreshBestScore() {
    textBestScore.setString("Best score: " + std::to_string(bestScore));
}
