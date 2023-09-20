#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain& brain)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    for (int i = 0; i < this->size; i++)
        this->ideas[i] = brain.ideas[i];
}

Brain& Brain::operator=(const Brain& brain)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &brain)
    {
        for (int i = 0; i < this->size; i++)
            this->ideas[i] = brain.ideas[i];
    }
    return (*this);
}

void Brain::setideas()
{
    ideas[0] = "hello";
    ideas[1] = "world";
}

void Brain::printideas()
{
    std::cout << ideas[0] << " " << ideas[1] << std::endl;
    std::cout << &ideas[0] << " " << &ideas[1] << std::endl;
}