#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongcat) : WrongAnimal(wrongcat)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongcat)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    if (this == &wrongcat)
        return (*this);
    this->type = wrongcat.type;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << this->type << " : Hi! I'm Haerin" << std::endl;
}

std::string WrongCat::getType() const
{
    return (this->type);
}