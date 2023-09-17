#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string name;

public:
    DiamondTrap(int hit_points = 100, int energy_points = 100, int attack_damage = 30);
    DiamondTrap(std::string name, int hit_points = 100, int energy_points = 100, int attack_damage = 30);
    DiamondTrap(const DiamondTrap& dt);
    DiamondTrap& operator=(const DiamondTrap &dt);
    ~DiamondTrap();

};

#endif
