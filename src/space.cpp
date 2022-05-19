// Space class definition

#include "../lib/space.hpp"


void Space::add(std::unique_ptr<SpaceElement> element) {
    toAdd.push_back(std::move(element));
}

void Space::refresh() {
    float timedelta = clock.restart().asSeconds();
    for (unsigned int i = 0; i < elements.size(); i++)
        elements[i]->refresh(timedelta);
}

void Space::testCollisions() {
    asteroids = false;
    for (unsigned int i = 0; i < elements.size(); i++) {
        if (elements[i]->getType() == ElementType::ASTEROID || elements[i]->getType() == ElementType::OTHER)
            asteroids = true;
        for (unsigned int j = 0; j < elements.size(); j++)
            if (i != j) elements[i]->testCollision(*elements[j]);
    }
}

void Space::display(sf::RenderWindow& window) const {
    for (const std::unique_ptr<SpaceElement>& element: elements)
        element->display(window);
}

void Space::clear() {
    if (toFree) {
        elements.clear();
        toFree = false;
    }
    auto end = std::remove_if(std::begin(elements), std::end(elements), SpaceElement::isDestructed);
    elements.erase(end, std::end(elements));
    for (std::unique_ptr<SpaceElement>& element: toAdd) {
        if (element->getType() == ElementType::ASTEROID || element->getType() == ElementType::OTHER)
            asteroids = true;
        elements.push_back(std::move(element));
    }
    toAdd.clear();
}

void Space::free() {
    toFree = true;
}
