#include "Array.hpp"

int main(void)
{
    try
    {
        Array<int> a(10);
        std::cout << a.size() << std::endl;
        std::cout << a[2] << std:: endl;
        Array<int> b = a;
        std::cout << b.size() << std::endl;
        std::cout << b[1] << std:: endl;
        Array<int> c(a);
        std::cout << c.size() << std::endl;
        std::cout << c[20] << std:: endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
