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
};

#endif

// inherit the constructors and destructor
// its constructors, destructor and attack() will print different messages

// Name, which is passed as parameter to a constructor
// •Hit points (100), represent the health of the ClapTrap
// •Energy points (50)
// •Attack damage (20)
// ScavTrap will also have its own special capacity:
// void guardGate();