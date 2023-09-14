#include "Fixed.hpp"

Fixed::Fixed()
{
    this->raw = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    this->raw = fixed.raw;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    if (this == &fixed)
        return (*this);
    std::cout << "Copy assignment operator called" << std::endl;
    this->raw = fixed.raw;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->raw);
}

void Fixed::setRawBits(int const raw)
{
    this->raw = raw;
    std::cout << "setRawBits member function called" << std::endl;
}
