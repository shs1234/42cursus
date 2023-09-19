#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap Default Constructor called" << std::endl;
    this->name = "noname";
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}
FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap Constructor called" << std::endl;
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}
FragTrap::FragTrap(const FragTrap& ft) : ClapTrap(ft)
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