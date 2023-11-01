#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <algorithm>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& sc);
    ScalarConverter& operator=(const ScalarConverter& sc);
    ~ScalarConverter();

public:
    static void convert(std::string n);
};

#endif
