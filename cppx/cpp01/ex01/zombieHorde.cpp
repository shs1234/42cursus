#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *zb = new Zombie[N];
    if (!zb)
        return (0);
    for (int i = 0; i < N; i++)
        zb[i].setName(name);
    return (zb);
}
