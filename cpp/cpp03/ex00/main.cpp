#include "ClapTrap.hpp"

int main()
{
    {
        ClapTrap ct("hoseoson");

        for (int i=0; i < 12;i++)
            ct.attack("target");
        ct.beRepaired(10);
        ct.takeDamage(5);
    }
    std::cout << std::endl;
    {
        ClapTrap ct("hoseoson");

        ct.attack("target");
        ct.beRepaired(10);
        for (int i=0; i < 5;i++)
            ct.takeDamage(5);
        ct.beRepaired(10);
    }
    std::cout << std::endl;
    {
        ClapTrap ct("hoseoson");

        ct.attack("target");
        ct.takeDamage(5);
        for (int i=0; i < 10;i++)
            ct.beRepaired(10);
    }
    return (0);
}