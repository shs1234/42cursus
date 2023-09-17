#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(int hit_points, int energy_points, int attack_damage)
: ClapTrap(hit_points, energy_points, attack_damage)
{
    std::cout << "DiamondTrap Constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name, int hit_points, int energy_points, int attack_damage)
: ClapTrap(name, hit_points, energy_points, attack_damage)
{
    std::cout << "DiamondTrap Constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& dt)
: ClapTrap(dt)
{
    std::cout << "DiamondTrap copy Constructor called" << std::endl;
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap &dt)
{
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &dt)
        ClapTrap::operator=(dt);
    return (*this);
}
