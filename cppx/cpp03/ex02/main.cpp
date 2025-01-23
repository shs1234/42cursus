#include "FragTrap.hpp"

int main()
{
    FragTrap ft("hoseoson");

    ft.attack("target");
    ft.takeDamage(5);
    ft.beRepaired(10);
    ft.highFivesGuys();
    return (0);
}
