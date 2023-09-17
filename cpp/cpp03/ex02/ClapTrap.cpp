#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
: name("noname"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ct)
: name(ct.name), hit_points(ct.hit_points), energy_points(ct.energy_points), attack_damage(ct.attack_damage)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ct)
{
    std::cout << "ClapTrap Assignment operator called" << std::endl;
    if (this != &ct)
    {
        this->name = ct.name;
        this->hit_points = ct.hit_points;
        this->energy_points = ct.energy_points;
        this->attack_damage = ct.attack_damage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hit_points <= 0)
    {
        std::cout << "attackfail : " << this->name << " is dead" << std::endl;
        return;
    }
    if (this->energy_points <= 0)
    {
        std::cout << "attackfail : not enough energy_point" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy_points--;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points <= 0)
    {
        std::cout << this->name << " is already dead" << std::endl;
        return;
    }
    std::cout << this->name << " takes " << amount << " points of damage!" << std::endl;
    this->hit_points -= amount;
    if (this->hit_points <= 0)
        std::cout << this->name << " is dead" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points <= 0)
    {
        std::cout << "repairfail : " << this->name << " is dead" << std::endl;
        return;
    }
    if (this->energy_points <= 0)
    {
        std::cout << "repairfail : not enough energy_point" << std::endl;
        return;
    }
    std::cout << this->name << " is repaired, so get " << amount << " hit point(s)" << std::endl;
    this->energy_points--;
    this->hit_points += amount;
}
