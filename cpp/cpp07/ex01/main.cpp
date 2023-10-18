#include "iter.hpp"

int main(void)
{
    const int len = 3;
    std::string s[len] = {"s1", "s2", "s3"};
    int i[len] = {1, 2, 3};

    iter(s, len, test);
    // iter(i, len, test);
    iter(s, len, print<std::string>);
    iter(i, len, print<int>);
}
