#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog& dog)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    this->type = dog.type;
}

Dog& Dog::operator=(const Dog& dog)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &dog)
        this->type = dog.type;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << this->type << " : mung! mung!" << std::endl;
}

const std::string& Dog::getType() const
{
    return (this->type);
}