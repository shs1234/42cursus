#include "Fixed.hpp"

Fixed::Fixed()
{
    this->raw = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw)
{
    this->raw = raw << fractional_bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float raw)
{
    this->raw = (int)(roundf(raw * (1 << fractional_bits)));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    if (this == &fixed)
        return (*this);
    std::cout << "Copy assignment operator called" << std::endl;
    this->raw = fixed.raw;
    return (*this);
}

std::ostream& operator<<(std::ostream &cout, const Fixed& fixed)
{
    cout << fixed.toFloat();
    return (cout);
}

float Fixed::toFloat() const
{
    return ((float)this->raw / (float)(1 << fractional_bits));
}

int Fixed::toInt() const
{
    return ((int)this->raw >> fractional_bits);
}
