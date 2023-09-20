#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : name("noname")
{
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
    ClapTrap::name = name + "_clap_name";
    this->energy_points = 50;
}
DiamondTrap::DiamondTrap(std::string name) : name(name)
{
    std::cout << "DiamondTrap Constructor called" << std::endl;
    ClapTrap::name = name + "_clap_name";
    this->energy_points = 50;
}
DiamondTrap::DiamondTrap(const DiamondTrap& dt)
: ClapTrap(dt), ScavTrap(dt), FragTrap(dt), name(dt.name)
{
    std::cout << "DiamondTrap Copy Constructor called" << std::endl;
    ClapTrap::name = name + "_clap_name";
    this->energy_points = 50;
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap &dt)
{
    std::cout << "DiamondTrap Assignment operator called" << std::endl;
    if (this != &dt)
    {
        FragTrap::operator=(dt);
        this->name = dt.name;
    }
    return (*this);
}

void DiamondTrap::whoAmI()
{
    std::cout << "---whoAmI---" << std::endl;
    std::cout << "name : " << this->name << std::endl;
    std::cout << "ClapTrap name : " << ClapTrap::name << std::endl;
    std::cout << "hit_points : " << this->hit_points << std::endl;
    std::cout << "energy_points : " << this->energy_points << std::endl;
    std::cout << "attack_damage : " << this->attack_damage << std::endl;
}