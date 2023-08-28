#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int i_raw;
    float f_raw;
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
};

std::ostream& operator<<(std::ostream &cout, const Fixed& fixed);

#endif
