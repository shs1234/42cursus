#include "Fixed.hpp"

Fixed::Fixed() : raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw)
{
    std::cout << "Int constructor called" << std::endl;
    this->raw = raw << fractional_bits;
}

Fixed::Fixed(const float raw)
{
    std::cout << "Float constructor called" << std::endl;
    this->raw = roundf(raw * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed& fixed) : raw(fixed.raw)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->raw = fixed.raw;
    return (*this);
}

float Fixed::toFloat() const
{
    return ((float)this->raw / (float)(1 << fractional_bits));
}

int Fixed::toInt() const
{
    return ((int)this->raw >> fractional_bits);
}

std::ostream& operator<<(std::ostream &cout, const Fixed& fixed)
{
    cout << fixed.toFloat();
    return (cout);
}
