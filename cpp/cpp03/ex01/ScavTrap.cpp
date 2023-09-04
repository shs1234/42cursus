#include "ScavTrap.hpp"

ScavTrap::ScavTrap(int hit_points, int energy_points, int attack_damage)
: ClapTrap(hit_points, energy_points, attack_damage)
{
    std::cout << "ScavTrap constructor called" << std::endl;
}
ScavTrap::ScavTrap(std::string name, int hit_points, int energy_points, int attack_damage)
: ClapTrap(name, hit_points, energy_points, attack_damage)
{
    std::cout << "ScavTrap constructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& st)
{
    (void)st;
    std::cout << "ScavTrap copy constructor called" << std::endl;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap &st)
{
    (void)st;
    std::cout << "ScavTrap assignment operator called" << std::endl;
    return (*this);
}

void ScavTrap::guardGate()
{

}

// 상속받을때 대입연산자같은거 어떻게 처리되는지? 변수 옮겨져야할텐데