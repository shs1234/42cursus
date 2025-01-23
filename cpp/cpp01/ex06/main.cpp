#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage : ./harlFilter LEVEL" << std::endl;
        return (1);
    }
    std::string level;
    level = av[1];
    int i;
    if (level == "DEBUG")
        i = 0;
    else if (level == "INFO")
        i = 1;
    else if (level == "WARNING")
        i = 2;
    else if (level == "ERROR")
        i = 3;
    else
        i = 4;

    Harl harl;
    switch (i)
    {
    case 0:
        harl.complain("DEBUG");
        // fall through
    case 1:
        harl.complain("INFO");
        // fall through
    case 2:
        harl.complain("WARNING");
        // fall through
    case 3:
        harl.complain("ERROR");
        break;
    case 4:
        harl.complain("else");
    }
    return (0);
}
