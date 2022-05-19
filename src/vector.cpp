// Vector class definition

#include "../lib/vector.hpp"
#include "cmath"


Vector::Vector(float x, float y): x(x), y(y) {}

void Vector::operator +=(const Vector& other) {
    x += other.x;
    y += other.y;
}

void Vector::operator -=(const Vector& other) {
    x -= other.x;
    y -= other.y;
}

Vector Vector::operator *(float coeff) const {
    return Vector(x * coeff, y * coeff);
}

Vector Vector::fromSizeAndAngle(float size, float angle) {
    return Vector(size * cos(angle / 180.f * M_PI), size * sin(angle / 180.f * M_PI));
}
