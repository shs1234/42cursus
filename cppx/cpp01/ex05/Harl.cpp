#include "Harl.hpp"

Harl::Harl()
{
    set[0].str = "DEBUG";
    set[0].ptr = &Harl::debug;
    set[1].str = "INFO";
    set[1].ptr = &Harl::info;
    set[2].str = "WARNING";
    set[2].ptr = &Harl::warning;
    set[3].str = "ERROR";
    set[3].ptr = &Harl::error;
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    Harl harl;

    for (int i = 0; i < 4; i++)
    {
        if (level == set[i].str)
            (harl.*set[i].ptr)();
    }
}
