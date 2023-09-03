#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
    std::string name;
    int hit;
    int energy;
    int attack;

public:
    ClapTrap();
    ClapTrap(const ClapTrap& ct);
    ~ClapTrap();
    ClapTrap& operator=(const ClapTrap &ct);


};

#endif
