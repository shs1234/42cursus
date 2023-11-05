#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

void test(std::string item)
{
    std::cout << item << std::endl;
}

template <typename T>
void print(T &item)
{
    std::cout << item << std::endl;
}

template <typename T1, typename T2>
void iter(T1 *arr, T2 len, void (*f)(const T1&))
{
    for (T2 i = 0; i < len; i++)
        f(arr[i]);
}

#endif
