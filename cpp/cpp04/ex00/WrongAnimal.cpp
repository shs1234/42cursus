#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Unknown")
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wronganimal)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    this->type = wronganimal.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wronganimal)
{
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    if (this == &wronganimal)
        return (*this);
    this->type = wronganimal.type;
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << this->type << " : ???" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}