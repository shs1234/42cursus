#include <iostream>
#include <cstdlib> // For strtod
#include <stdio.h>
int main() {
    std::string n = "-340282357639528859811704183484516925445.0000000000000000";
    char *endp;
    float f = std::strtof(n.c_str(), 0);
    std::cout << std::numeric_limits<float>::max() << std::endl;
    std::cout << f << std::endl;
    if (-f == std::numeric_limits<float>::infinity())
        std::cout << "true";
}
