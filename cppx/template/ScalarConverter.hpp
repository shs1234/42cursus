#pragma once

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
