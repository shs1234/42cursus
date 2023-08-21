#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
{
    this->setType(type);
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
