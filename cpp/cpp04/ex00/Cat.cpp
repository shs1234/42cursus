#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this == &cat)
        return (*this);
    this->type = cat.type;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << this->type << " : Hi! I'm Haerin" << std::endl;
}

const std::string& Cat::getType() const
{
    return (this->type);
}