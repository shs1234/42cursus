#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
    static const int size = 100;
    std::string ideas[size];

public:
    Brain();
    Brain(const Brain& brain);
    Brain& operator=(const Brain& brain);
    ~Brain();

    void setideas();
    void printideas();
};

#endif
