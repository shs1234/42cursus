#include "Fixed.hpp"

Fixed::Fixed()
{
    this->i_raw = 0;
    this->f_raw = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw)
{
    this->i_raw = raw;
    this->f_raw = 0;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float raw)
{
    this->i_raw = 0;
    this->f_raw = raw;
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
    std::cout << "Copy assignment operator called" << std::endl;
    this->f_raw = fixed.f_raw;
    this->i_raw = fixed.i_raw;
    return (*this);
}

std::ostream& operator<<(std::ostream &cout, const Fixed& fixed)
{
    cout << fixed.toFloat();
    return (cout);
}

float Fixed::toFloat() const
{
    if (this->f_raw)
        return (this->f_raw);
    return (this->i_raw);
}

int Fixed::toInt() const
{
    if (this->i_raw)
        return (this->i_raw);
    return (this->f_raw);
}
