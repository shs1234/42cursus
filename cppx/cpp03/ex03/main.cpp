#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dt("dt1");
    std::cout << std::endl;
    DiamondTrap dt2(dt);
    std::cout << std::endl;
    DiamondTrap dt3;
    dt3 = dt;
    std::cout << std::endl;
    dt.whoAmI();
    dt2.whoAmI();
    dt3.whoAmI();
    std::cout << std::endl;
    return (0);
}
