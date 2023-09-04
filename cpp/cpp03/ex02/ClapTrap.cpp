#include "ClapTrap.hpp"

ClapTrap::ClapTrap(int hit_points, int energy_points, int attack_damage)
: hit_points(hit_points), energy_points(energy_points), attack_damage(attack_damage)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string name, int hit_points, int energy_points, int attack_damage)
: name(name), hit_points(hit_points), energy_points(energy_points), attack_damage(attack_damage)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& ct)
: name(ct.name), hit_points(ct.hit_points), energy_points(ct.energy_points), attack_damage(ct.attack_damage)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap &ct)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this == &ct)
        return (*this);
    name = ct.name;
    hit_points = ct.hit_points;
    energy_points = ct.energy_points;
    attack_damage = ct.attack_damage;
    return (*this);
}


void ClapTrap::attack(const std::string& target)
{
    if (getEnergy() <= 0 || getHit() <= 0)
        return ;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    costEnergy();
}
void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << this->name << " takes " << amount << " points of damage!" << std::endl;
    this->hit_points -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (getEnergy() <= 0 || getHit() <= 0)
        return ;
    std::cout << this->name << " is repaired, so get " << amount << " hit points" << std::endl;
    costEnergy();
    this->hit_points += amount;
}

std::string ClapTrap::getName() const
{
    return (name);
}
int ClapTrap::getHit() const
{
    return (hit_points);
}
int ClapTrap::getEnergy() const
{
    return (energy_points);
}
int ClapTrap::getAttack() const
{
    return (attack_damage);
}

void ClapTrap::costEnergy()
{
    this->energy_points--;
}
