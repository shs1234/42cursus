#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("hoseoson", 149);

        std::cout << b.getName() << " " << b.getGrade() << std::endl;
        b.increaseGrade();
        std::cout << b;
        b.decreaseGrade();
        std::cout << b;
        b.decreaseGrade();
        std::cout << b;
        b.decreaseGrade();
        std::cout << b;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
