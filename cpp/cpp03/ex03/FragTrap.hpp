#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:

public:
    FragTrap(int hit_points = 100, int energy_points = 100, int attack_damage = 30);
    FragTrap(std::string name, int hit_points = 100, int energy_points = 100, int attack_damage = 30);
    FragTrap(const FragTrap& ft);
    FragTrap& operator=(const FragTrap &ft);
    ~FragTrap();

    void highFivesGuys();
};

#endif
