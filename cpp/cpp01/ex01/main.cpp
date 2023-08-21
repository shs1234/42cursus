#include "Zombie.hpp"

int main()
{
    int N = 5;
    std::string name = "random";
    Zombie *zb = zombieHorde(N, name);
    if (!zb)
        return (1);
    for (int i = 0; i < N; i++)
        zb[i].announce();
    delete[] zb;
    return (0);
}
