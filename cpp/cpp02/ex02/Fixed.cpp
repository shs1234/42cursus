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

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
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
    this->raw *= fixed.raw;
    return (*this);
}
Fixed& Fixed::operator/(const Fixed& fixed) // 분모가 0인지 확인
{
    this->raw /= fixed.raw;
    return (*this);
}


int Fixed::operator++() // 전위
{
    this->raw++;
    return (this->raw);
}
int Fixed::operator++(int)
{
    int tmp = this->raw;
    this->raw++;
    return (tmp);
}
int Fixed::operator--()
{
    this->raw--;
    return (this->raw);
}
int Fixed::operator--(int)
{
    int tmp = this->raw;
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
