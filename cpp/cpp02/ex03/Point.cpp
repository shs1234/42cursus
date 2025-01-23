#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}
Point::Point(const float x, const float y) : x(x), y(y)
{
}
Point::Point(const Point& p) : x(p.x), y(p.y)
{
}
Point& Point::operator=(const Point& p)
{
    (void)p;
    return (*this);
}
Point::~Point()
{
}

float Point::getx() const
{
    return (x.toFloat());
}
float Point::gety() const
{
    return (y.toFloat());
}