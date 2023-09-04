#include "ClapTrap.hpp"

int main()
{
    ClapTrap ct("hoseoson");

    ct.attack("target");
    ct.takeDamage(5);
    ct.beRepaired(10);
    return (0);
}