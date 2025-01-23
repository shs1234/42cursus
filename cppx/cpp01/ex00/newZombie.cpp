#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *zb = new Zombie;
    if (!zb)
        return (0);
    zb->setName(name);
    return (zb);
}
