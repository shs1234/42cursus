#include "Animal.hpp"

Animal::Animal() : type("Unknown")
{
    std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal Constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal& animal) : type(animal.type)
{
    std::cout << "Animal Copy Constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& animal)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &animal)
        this->type = animal.type;
    return (*this);
}

void Animal::makeSound() const
{
    std::cout << this->type << " : ???" << std::endl;
}

const std::string& Animal::getType() const
{
    return (this->type);
}