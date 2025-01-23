#include "Zombie.hpp"

int main()
{
    Zombie *zb;

    zb = newZombie("new1");
    if (!zb)
        return (1);
    zb->announce();
    delete zb;

    randomChump("new2");

    return (0);
}
