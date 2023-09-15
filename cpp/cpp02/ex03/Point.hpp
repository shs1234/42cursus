#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include "Fixed.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;

public:
    Point();
    Point(const float x, const float y);
    Point(const Point& p);
    Point& operator=(const Point& p);
    ~Point();

    float getx() const;
    float gety() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif

// 변수 
//     const Fixed x;
//     const Fixed y;
//     로 바꿀것

// 카피 연산자 const일때 private로