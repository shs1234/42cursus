#include "Fixed.hpp"

Fixed::Fixed()
{
    this->raw = 0;
}
Fixed::Fixed(const int raw)
{
    this->raw = raw << fractional_bits;
}
Fixed::Fixed(const float raw)
{
    this->raw = (int)(roundf(raw * (1 << fractional_bits)));
}
Fixed::Fixed(const Fixed& fixed)
{
    *this = fixed;
}
Fixed& Fixed::operator=(const Fixed& fixed)
{
    if (this == &fixed)
        return (*this);
    this->raw = fixed.raw;
    return (*this);
}
Fixed::~Fixed()
{
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


int Fixed::operator>(const Fixed& fixed)
{
    return (this->raw > fixed.raw);
}
int Fixed::operator<(const Fixed& fixed)
{
    return (this->raw < fixed.raw);
}
int Fixed::operator>=(const Fixed& fixed)
{
    return (this->raw >= fixed.raw);
}
int Fixed::operator<=(const Fixed& fixed)
{
    return (this->raw <= fixed.raw);
}
int Fixed::operator==(const Fixed& fixed)
{
    return (this->raw == fixed.raw);
}
int Fixed::operator!=(const Fixed& fixed)
{
    return (this->raw != fixed.raw);
}


Fixed& Fixed::operator+(const Fixed& fixed)
{
    this->raw += fixed.raw;
    return (*this);
}
Fixed& Fixed::operator-(const Fixed& fixed)
{
    this->raw -= fixed.raw;
    return (*this);
}
Fixed& Fixed::operator*(const Fixed& fixed)
{
    float tmp = this->toFloat() * fixed.toFloat();
    this->raw = (int)(roundf(tmp * (1 << fractional_bits)));
    return (*this);
}
Fixed& Fixed::operator/(const Fixed& fixed)
{
    if (fixed.raw == 0)
        std::cout << "warning : Division By Zero" << std::endl;
    float tmp = this->toFloat() / fixed.toFloat();
    this->raw = (int)(roundf(tmp * (1 << fractional_bits)));
    return (*this);
}


float Fixed::operator++()
{
    this->raw++;
    return (this->toFloat());
}
float Fixed::operator++(int) 
{
    float tmp = this->toFloat();
    this->raw++;
    return (tmp);
}
float Fixed::operator--()
{
    this->raw--;
    return (this->toFloat());
}
float Fixed::operator--(int)
{
    float tmp = this->toFloat();
    this->raw--;
    return (tmp);
}


Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1.raw >= fixed2.raw)
        return (fixed2);
    return (fixed1);
}
Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1.raw >= fixed2.raw)
        return (fixed1);
    return (fixed2);
}
const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1.raw >= fixed2.raw)
        return (fixed2);
    return (fixed1);
}
const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1.raw >= fixed2.raw)
        return (fixed1);
    return (fixed2);
}
