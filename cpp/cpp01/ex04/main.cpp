#include "MySed.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Usage : ./mysed infile s1 s2" << std::endl;
        return (1);
    }
    MySed mysed(av[1], av[2], av[3]);
    if (!mysed.is_open())
    {
        std::cout << "file open error" << std::endl;
        return (1);
    }
    mysed.sed();
    mysed.close();
    return (0);
}
