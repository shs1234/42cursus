#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
private:

public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& sc);
    ScalarConverter& operator=(const ScalarConverter& sc);
    ~ScalarConverter();
};

#endif
