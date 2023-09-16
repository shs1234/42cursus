#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
    std::string name;
    int hit_points;
    int energy_points;
    int attack_damage;
    ClapTrap();

public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& ct);
    ~ClapTrap();
    ClapTrap& operator=(const ClapTrap &ct);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
