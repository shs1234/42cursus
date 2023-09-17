#include "ClapTrap.hpp"

ClapTrap::ClapTrap(int hit_points, int energy_points, int attack_damage) 
: name("noname"), hit_points(hit_points), energy_points(energy_points), attack_damage(attack_damage)
{
    std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hit_points, int energy_points, int attack_damage) 
: name(name), hit_points(hit_points), energy_points(energy_points), attack_damage(attack_damage)
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
    if (getHit() <= 0)
    {
        std::cout << "attackfail : " << getName() << " is dead" << std::endl;
        return;
    }
    if (getEnergy() <= 0)
    {
        std::cout << "attackfail : not enough energy_point" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttack() << " points of damage!" << std::endl;
    costEnergy();
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (getHit() <= 0)
    {
        std::cout << getName() << " is already dead" << std::endl;
        return;
    }
    std::cout << getName() << " takes " << amount << " points of damage!" << std::endl;
    this->hit_points -= amount;
    if (getHit() <= 0)
        std::cout << getName() << " is dead" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (getHit() <= 0)
    {
        std::cout << "repairfail : " << getName() << " is dead" << std::endl;
        return;
    }
    if (getEnergy() <= 0)
    {
        std::cout << "repairfail : not enough energy_point" << std::endl;
        return;
    }
    std::cout << getName() << " is repaired, so get " << amount << " hit point(s)" << std::endl;
    costEnergy();
    this->hit_points += amount;
}

int ClapTrap::getAttack() const
{
    return (this->attack_damage);
}
int ClapTrap::getEnergy() const
{
    return (this->energy_points);
}
int ClapTrap::getHit() const
{
    return (this->hit_points);
}
void ClapTrap::costEnergy()
{
    this->energy_points--;
}
const std::string& ClapTrap::getName()
{
    return (this->name);
}
