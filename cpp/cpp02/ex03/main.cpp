#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
    Point a(1, 1);
    Point b(4, 1);
    Point c(2, 3);

    Point p1(2, 2);
    if (bsp(a, b, c, p1))
        std::cout << "inside" << std::endl;
    else
        std::cout << "outside" << std::endl;

    Point p2(3, 3);
    if (bsp(a, b, c, p2))
        std::cout << "inside" << std::endl;
    else
        std::cout << "outside" << std::endl;
        
    return (0);
}
