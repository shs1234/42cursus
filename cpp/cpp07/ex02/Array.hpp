#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
    T *_arr;
    unsigned int _n;

public:
    Array();
    Array(unsigned int n);
    Array(const Array<T> &arr);
    ~Array();
    Array<T> &operator=(const Array<T> &arr);
    T &operator[](unsigned int i) const;

    unsigned int size() const;

    class IndexIsOutOfBounds : public std::exception
    {
        const char *what() const throw();
    };
};

template <typename T>
Array<T>::Array() : _n(0)
{
    _arr = new T[_n];
}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n)
{
    _arr = new T[_n];
}

template <typename T>
Array<T>::Array(const Array<T> &arr)
{
    _n = arr._n;
    _arr = new T[_n];
    for (unsigned int i = 0; i < _n; i++)
        _arr[i] = arr[i];
}

template <typename T>
Array<T>::~Array()
{
    delete[] _arr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &arr)
{
    if (this != &arr)
    {
        delete[] _arr;
        _arr = new T[_n];
        for (unsigned int i = 0; i < _n; i++)
            _arr[i] = arr[i];
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i) const
{
    if (i >= _n)
        throw IndexIsOutOfBounds();
    return (_arr[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_n);
}

template <typename T>
const char *Array<T>::IndexIsOutOfBounds::what() const throw()
{
    return ("Index is out of bounds");
}

#endif
