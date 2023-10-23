#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
bool easyfind(T &arr, int item)
{
    if (std::find(arr.begin(), arr.end(), item) == arr.end())
        return (0);
    return (1);
}

#endif
