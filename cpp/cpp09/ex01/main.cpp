#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: ac != 2" << std::endl;
        return (1);
    }
    try
    {
        RPN rpn(av[1]);
        rpn.calc();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
