#include "ClapTrap.hpp"

ClapTrap::ClapTrap(int hit_points, int energy_points, int attack_damage)
: name("noname"), hit_points(hit_points), energy_points(energy_points), attack_damage(attack_damage)
{
    std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hit_points, int energy_points, int attack_damage)
: name(name), hit_points(hit_points), energy_points(energy_points), attack_damage(attack_damage)
{
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ct)
: name(ct.name), hit_points(ct.hit_points), energy_points(ct.energy_points), attack_damage(ct.attack_damage)
{
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ct)
{
    std::cout << "Assignment operator called" << std::endl;
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
        std::cout << "attackfail : " << "ClapTrap " << this->name << " is dead" << std::endl;
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
        std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
    this->hit_points -= amount;
    if (this->hit_points <= 0)
        std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points <= 0)
    {
        std::cout << "repairfail : " << "ClapTrap " << this->name << " is dead" << std::endl;
        return;
    }
    if (this->energy_points <= 0)
    {
        std::cout << "repairfail : not enough energy_point" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " is repaired, so get " << amount << " hit point(s)" << std::endl;
    this->energy_points--;
    this->hit_points += amount;
}
