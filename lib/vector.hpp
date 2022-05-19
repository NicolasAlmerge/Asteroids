// Vector class declaration

#pragma once


class Vector {
    float x = 0.f;
    float y = 0.f;

public:
    Vector() = default;
    Vector(float x, float y);

    inline float getX() const {return x;}
    inline float getY() const {return y;}
    inline void setX(float newX) {x = newX;}
    inline void setY(float newY) {y = newY;}

    void operator +=(const Vector&);
    void operator -=(const Vector&);
    Vector operator *(float) const;

    static Vector fromSizeAndAngle(float, float);
};
