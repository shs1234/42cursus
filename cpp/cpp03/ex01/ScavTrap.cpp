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
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &st)
        ClapTrap::operator=(st);
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (getHit() <= 0)
    {
        std::cout << "attackfail : " << "ScavTrap " << getName() << " is dead" << std::endl;
        return;
    }
    if (getEnergy() <= 0)
    {
        std::cout << "attackfail : not enough energy_point" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttack() << " points of damage!" << std::endl;
    costEnergy();
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gatekeeper mode." << std::endl;
}

