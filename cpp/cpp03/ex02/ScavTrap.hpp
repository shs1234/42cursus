#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

public:
    ScavTrap(int hit_points = 100, int energy_points = 50, int attack_damage = 20);
    ScavTrap(std::string name, int hit_points = 100, int energy_points = 50, int attack_damage = 20);
    ScavTrap(const ScavTrap& st);
    ScavTrap& operator=(const ScavTrap &st);
    ~ScavTrap();

    void guardGate();
    void attack(const std::string& target);
};

#endif
