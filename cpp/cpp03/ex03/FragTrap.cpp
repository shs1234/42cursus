#include "FragTrap.hpp"

FragTrap::FragTrap(int hit_points, int energy_points, int attack_damage)
: ClapTrap(hit_points, energy_points, attack_damage)
{
    std::cout << "FragTrap constructor called" << std::endl;
}
FragTrap::FragTrap(std::string name, int hit_points, int energy_points, int attack_damage)
: ClapTrap(name, hit_points, energy_points, attack_damage)
{
    std::cout << "FragTrap constructor called" << std::endl;
}
FragTrap::FragTrap(const FragTrap& ft)
: ClapTrap(ft)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap &ft)
{
    ClapTrap::operator=(ft);
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this == &ft)
        return (*this);
    return (*this);
}

void FragTrap::highFivesGuys()
{
    std::cout << "a positive high fives request" << std::endl;
}