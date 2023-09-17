#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->name = "noname";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}
ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}
ScavTrap::ScavTrap(const ScavTrap& st) : ClapTrap(st)
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
    if (this->hit_points <= 0)
    {
        std::cout << "attackfail : " << "ScavTrap " << this->name << " is dead" << std::endl;
        return;
    }
    if (this->energy_points <= 0)
    {
        std::cout << "attackfail : not enough energy_point" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy_points--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gatekeeper mode." << std::endl;
}

