#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(const MutantStack<T> &obj);
    ~MutantStack();
    MutantStack<T> &operator=(const MutantStack<T> &obj);

    class iterator
    {
    private:
        T *_it;
    public:
        T operator++();
        T operator--();
        bool operator!=(const MutantStack<T>::iterator &obj);
        T operator*();
    };
    typename std::deque<T>::iterator begin();
    typename std::deque<T>::iterator end();
};

template <typename T>
MutantStack<T>::MutantStack() {}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &obj) : std::stack<T>(obj) {}
template <typename T>
MutantStack<T>::~MutantStack() {}
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &obj)
{
    if (this != &obj)
        std::stack<T>::operator=(obj);
    return (*this);
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::begin()
{
    return std::deque<T>::begin();
}
template <typename T>
typename std::deque<T>::iterator MutantStack<T>::end()
{
    return std::deque<T>::end();
}

template <typename T>
T MutantStack<T>::iterator::operator++()
{
    ++_it;
    return (*_it);
}
template <typename T>
T MutantStack<T>::iterator::operator--()
{
    --_it;
    return (*_it);
}
template <typename T>
bool MutantStack<T>::iterator::operator!=(const MutantStack<T>::iterator &obj)
{
    return (_it != obj._it);
}
template <typename T>
T MutantStack<T>::iterator::operator*()
{
    return (*_it);
}

#endif
