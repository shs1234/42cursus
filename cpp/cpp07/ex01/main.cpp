#include "iter.hpp"

int main(void)
{
    const std::size_t len = 3;
    std::string s[len] = {"s1", "s2", "s3"};
    int i[len] = {1, 2, 3};

    iter(s, len, print);
    iter(i, len, print);
}
