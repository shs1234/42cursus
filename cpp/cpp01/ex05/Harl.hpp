#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
private:
    typedef struct
    {
        std::string str;
        void (Harl::*ptr)(void);
    }levelset;
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    levelset set[4];

public:
    Harl();
    void complain(std::string level);
};

#endif
