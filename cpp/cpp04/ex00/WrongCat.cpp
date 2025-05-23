#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongcat)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    this->type = wrongcat.type;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongcat)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    if (this != &wrongcat)
        this->type = wrongcat.type;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << this->type << " : yaong" << std::endl;
}

const std::string &WrongCat::getType() const
{
    return (this->type);
}