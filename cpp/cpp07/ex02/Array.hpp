#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
    T *_arr;
    unsigned int _n;

public:
    Array();
    Array(unsigned int n);
    ~Array();
    Array(const Array &arr);
    Array &operator=(const Array &arr);

    unsigned int size() const;
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
Array<T>::Array(const Array &arr)
{
    _arr = new T[_n];
    for (int i = 0; i < _n; i++)
        _arr[i] = arr[i];
}

template <typename T>
Array &Array<T>::operator=(const Array &arr)
{
    if (_arr)
    {
        for (int i = 0; i < _n; i++)
            delete _arr[i];
    }
    _arr = new T[_n];
    for (int i = 0; i < _n; i++)
        _arr[i] = arr[i];
    return (*this);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_n);
}


#endif
