#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("hoseoson", 3);

        std::cout << b.getName() << " " << b.getGrade() << std::endl;
        b.increaseGrade();
        std::cout << b;
        b.decreaseGrade();
        std::cout << b;

        // b2 = b;
        std::cout << std::endl;
        Bureaucrat b2 = b;
        std::cout << b2;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
