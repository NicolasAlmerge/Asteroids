// Coordinates class declaration

#pragma once
#include "vector.hpp"


class Coordinates {
    inline static unsigned int W = 0;
    inline static unsigned int H = 0;
    float x = W / 2.f;
    float y = H / 2.f;

    void recalculate();

public:
    Coordinates() = default;
    Coordinates(float, float);

    inline float getX() const {return x;}
    inline float getY() const {return y;}
    inline void setX(float newX) {x = newX; recalculate();}
    inline void setY(float newY) {y = newY; recalculate();}

    void operator +=(const Vector&);
    float getDistanceTo(const Coordinates&) const;

    static void setSpaceLimits(unsigned int, unsigned int);

    inline static unsigned int getSpaceLength() {return W;}
    static unsigned int getSpaceHeight() {return H;}
};
