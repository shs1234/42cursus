#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
    Point a(-5, 0);
    Point b(5, 0);
    Point c(0, 5);

    Point p1(0, 1);
    if (bsp(a, b, c, p1))
        std::cout << "inside" << std::endl;
    else
        std::cout << "outside" << std::endl;

    Point p2(0, -1);
    if (bsp(a, b, c, p2))
        std::cout << "inside" << std::endl;
    else
        std::cout << "outside" << std::endl;
        
    return (0);
}
