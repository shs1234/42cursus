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
    return (*this);
}
Point::~Point()
{
}

int Point::getx() const
{
    return (x);
}
int Point::gety() const
{
    return (y);
}