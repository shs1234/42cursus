#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
    Weapon weapon;
    std::string name;
    
public:
    HumanA();
    HumanA(std::string name, Weapon weapon);
    void attack();
};

#endif
