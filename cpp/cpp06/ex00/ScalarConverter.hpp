#pragma once

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <limits>

class ScalarConverter
{
private:
    static bool _charOverflow;
    static bool _intOverflow;

    static bool _inf;
    static bool _inff;
    static bool _nan;
    static bool _nanf;

    static int _dot;
    static int _plus;
    static int _minus;

    static std::string detectType(std::string n);
    static bool	chkOverflow(const char *str, long long max);
    static int	numLen(long long n);




    ScalarConverter();
    ScalarConverter(const ScalarConverter& sc);
    ScalarConverter& operator=(const ScalarConverter& sc);
    ~ScalarConverter();

public:
    static void convert(std::string n);
};
