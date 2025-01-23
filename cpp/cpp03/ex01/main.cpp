#include "ScavTrap.hpp"

int main()
{
    ScavTrap st("hoseoson");

    st.attack("target");
    st.takeDamage(5);
    st.beRepaired(10);
    st.guardGate();
    return (0);
}
