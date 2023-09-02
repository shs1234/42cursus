#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int raw;
    static const int fractional_bits = 8;

public:
    Fixed();
    Fixed(const int raw);
    Fixed(const float raw);
    Fixed(const Fixed& fixed);
    Fixed& operator=(const Fixed& fixed);
    ~Fixed();

    float toFloat(void) const;
    int toInt(void) const;

    int operator>(const Fixed& fixed);
    int operator<(const Fixed& fixed);
    int operator>=(const Fixed& fixed);
    int operator<=(const Fixed& fixed);
    int operator==(const Fixed& fixed);
    int operator!=(const Fixed& fixed);

    Fixed& operator+(const Fixed& fixed);
    Fixed& operator-(const Fixed& fixed);
    Fixed& operator*(const Fixed& fixed);
    Fixed& operator/(const Fixed& fixed);

    int operator++();
    int operator++(int);
    int operator--();
    int operator--(int);

    static Fixed& min(Fixed& fixed1, Fixed& fixed2);
    static Fixed& max(Fixed& fixed1, Fixed& fixed2);
    static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
    static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
};

std::ostream& operator<<(std::ostream &cout, const Fixed& fixed);

#endif
