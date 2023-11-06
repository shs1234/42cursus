#include <vector>
#include <iostream>
// #include <stdlib.h>
int main()
{
    unsigned int a = 4294967290;
    unsigned int b = 4294967290;
    long long tmp = 0;
    // tmp = a + b;
    tmp += a;
    tmp += b;
    std::cout << tmp << std::endl;
    tmp = 4294967290 + 4294967290;
    std::cout << tmp;
    if (a < tmp)
        std::cout << "test";
}