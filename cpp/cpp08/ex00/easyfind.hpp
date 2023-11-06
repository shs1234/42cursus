#pragma once

#include <algorithm>

template <typename T>
bool easyfind(const T &arr, int item)
{
    if (std::find(arr.begin(), arr.end(), item) == arr.end())
        return (0);
    return (1);
}
