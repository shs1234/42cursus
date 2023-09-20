#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat& cat)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    this->thpe = cat.type;
}

Cat& Cat::operator=(const Cat& cat)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &cat)
        this->type = cat.type;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << this->type << " : yaong" << std::endl;
}

const std::string& Cat::getType() const
{
    return (this->type);
}