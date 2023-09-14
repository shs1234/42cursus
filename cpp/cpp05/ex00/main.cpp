#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b("hoseoson", 3);

    std::cout << b.getName() << " " << b.getGrade() << std::endl;
    std::cout << b;
    b.increaseGrade();
    std::cout << b;
    b.decreaseGrade();
    std::cout << b;

    // b2 = b;
    std::cout << std::endl;
    Bureaucrat b2 = b;
    std::cout << b2;
    return (0);
}