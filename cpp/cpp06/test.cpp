#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <limits>

int main() {
    // std::string n = "-340282357639528859811704183484516925445.0000000000000000";
    // char *endp;
    // float f = std::strtof(n.c_str(), 0);
    // std::cout << std::numeric_limits<float>::max() << std::endl;
    // std::cout << f << std::endl;
    // if (-f == std::numeric_limits<float>::infinity())
    //     std::cout << "true";

    // float f;// = 304748999999999456412312393650.0;
    // std::cout << HUGE_VAL-1;
    // const char *n = "3047489999999994532132131216412312393650.0f";
    // f = std::strtof(n, 0);
    // double d = static_cast<double>(f);
    // std::cout << f << std::endl;
    // std::cout << d << std::endl;
    // d = std::strtod(n, 0);
    // std::cout << d << std::endl;
    // // printf("%f", f);

    // std::string c = "inf";
    std::string c = "-2147483648";
    double d = std::strtof(c.c_str(), 0);
    int i;
    // std::istringstream(c) >> i;
    i = static_cast<int>(d);
    std::cout << d;
    std::cout << i;
}
