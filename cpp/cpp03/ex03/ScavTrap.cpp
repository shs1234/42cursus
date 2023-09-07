#include "ScavTrap.hpp"

ScavTrap::ScavTrap(int hit_points, int energy_points, int attack_damage)
: ClapTrap(hit_points, energy_points, attack_damage)
{
    std::cout << "ScavTrap constructor called" << std::endl;
}
ScavTrap::ScavTrap(std::string name, int hit_points, int energy_points, int attack_damage)
: ClapTrap(name, hit_points, energy_points, attack_damage)
{
    std::cout << "ScavTrap constructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& st)
: ClapTrap(st)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap &st)
{
    ClapTrap::operator=(st);
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this == &st)
        return (*this);
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (getEnergy() <= 0 || getHit() <= 0)
        return ;
    std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttack() << " points of damage!" << std::endl;
    costEnergy();
}

void ScavTrap::guardGate()
{
    std::cout << " ScavTrap is now in Gatekeeper mode." << std::endl;
}

