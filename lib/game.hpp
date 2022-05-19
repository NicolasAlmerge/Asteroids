// Game class declaration

#pragma once
#include "space.hpp"


class Game {
    Space& space;
    bool running = false;
    unsigned int score = 0;
    unsigned int bestScore = 0;
    sf::Text textScore;
    sf::Text textBestScore;
    sf::Text welcomeText;
    sf::Font font;
    std::unique_ptr<sf::Text> exceptionText;

    void refreshText();
    void refreshBestScore();

public:
    Game(Space&);
    void start();
    void end();
    void addPoints(unsigned int);
    inline bool isRunning() const {return running;}
    void display(sf::RenderWindow&) const;
    void initializeException(const std::exception&);
};
