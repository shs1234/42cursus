#include "Point.hpp"

float getarea(Point const a, Point const b, Point const c)
{
    float q;
    float p;

    q = a.getx()*b.gety() + b.getx()*c.gety() + c.getx()*a.gety();
    p = b.getx()*a.gety() + c.getx()*b.gety() + a.getx()*c.gety();

    return (std::abs(q - p) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float tri = getarea(a, b, c);
    float ab = getarea(a, b, point);
    float ac = getarea(a, point, c);
    float bc = getarea(point, b, c);

    if (ab + ac + bc == tri)
    {
        if (ab == 0 || ac == 0 || bc == 0)
            return (0);
        return (1);
    }
    return (0);
}
