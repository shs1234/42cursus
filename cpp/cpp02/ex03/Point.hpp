#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>

class Point
{
private:
    const int x;
    const int y;

public:
    Point();
    Point(const float x, const float y);
    Point(const Point& p);
    Point& operator=(const Point& p);
    ~Point();
    int getx() const;
    int gety() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
