// Coordinates class definition

#include "../lib/coordinates.hpp"
#include "cmath"
#include "algorithm"


Coordinates::Coordinates(float xCoor, float yCoor): x(xCoor), y(yCoor) {
    recalculate();
}

void Coordinates::setSpaceLimits(unsigned int width, unsigned int height) {
    W = width;
    H = height;
}

void Coordinates::operator +=(const Vector& vector) {
    x += vector.getX();
    y += vector.getY();
    recalculate();
}

float Coordinates::getDistanceTo(const Coordinates& other) const {
    float xCoor = std::min({abs(x - other.x), abs(x - other.x - W), abs(x - other.x + W)});
    float yCoor = std::min({abs(y - other.y), abs(y - other.y - H), abs(y - other.y + H)});
    return sqrt(xCoor * xCoor + yCoor * yCoor);
}

void Coordinates::recalculate() {
    while (x > W) x -= W;
    while (x < 0) x += W;
    while (y > H) y -= H;
    while (y < 0) y += H;
}
