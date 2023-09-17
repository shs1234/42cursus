#include "FragTrap.hpp"

FragTrap::FragTrap(int hit_points, int energy_points, int attack_damage)
: ClapTrap(hit_points, energy_points, attack_damage)
{
    std::cout << "FragTrap Constructor called" << std::endl;
}
FragTrap::FragTrap(std::string name, int hit_points, int energy_points, int attack_damage)
: ClapTrap(name, hit_points, energy_points, attack_damage)
{
    std::cout << "FragTrap Constructor called" << std::endl;
}
FragTrap::FragTrap(const FragTrap& ft)
: ClapTrap(ft)
{
    std::cout << "FragTrap copy Constructor called" << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap &ft)
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &ft)
        ClapTrap::operator=(ft);
    return (*this);
}

void FragTrap::highFivesGuys()
{
    std::cout << "a positive high fives request" << std::endl;
}