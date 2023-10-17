#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
T swap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

#endif
