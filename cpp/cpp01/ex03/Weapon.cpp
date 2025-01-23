#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
}

const std::string &Weapon::getType()
{
    const std::string &temp = this->type;
    return temp;
}

void Weapon::setType(std::string newtype)
{
    this->type = newtype;
}
