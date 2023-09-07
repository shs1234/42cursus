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

public:
    ClapTrap(int hit_points = 10, int energy_points = 10, int attack_damage = 0);
    ClapTrap(std::string name, int hit_points = 10, int energy_points = 10, int attack_damage = 0);
    ClapTrap(const ClapTrap& ct);
    ~ClapTrap();
    ClapTrap& operator=(const ClapTrap &ct);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName() const;
    int getHit() const;
    int getEnergy() const;
    int getAttack() const;

    void costEnergy();
};

#endif
