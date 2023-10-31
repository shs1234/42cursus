#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "no args" << std::endl;
        return (1);
    }
    try
    {
        PmergeMe pm(--ac, ++av);
        pm.exec();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }
    return (0);
}
