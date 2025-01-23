#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include "Fixed.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;

    Point& operator=(const Point& p);
public:
    Point();
    Point(const float x, const float y);
    Point(const Point& p);
    ~Point();

    float getx() const;
    float gety() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
