#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(const MutantStack<T> &obj);
    MutantStack<T> &operator=(const MutantStack<T> &obj);
    ~MutantStack();

    class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
    private:
        T *_it;

        iterator();
    public:
        iterator(T *it);
        iterator(const iterator &obj);
        iterator &operator=(const iterator &obj);
        ~iterator();

        iterator &operator++();
        iterator &operator--();
        bool operator!=(const iterator &obj);
        T &operator*();
    };
    iterator begin();
    iterator end();
};

template <typename T>
MutantStack<T>::MutantStack() {}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &obj) : std::stack<T>(obj) {}
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &obj)
{
    if (this != &obj)
        std::stack<T>::operator=(obj);
    return (*this);
}
template <typename T>
MutantStack<T>::~MutantStack() {}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return iterator(&this->top() - this->size() + 1);
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return iterator(&this->top() + 1);
}


template <typename T>
MutantStack<T>::iterator::iterator() {}
template <typename T>
MutantStack<T>::iterator::iterator(T *it) : _it(it) {}
template <typename T>
MutantStack<T>::iterator::iterator(const iterator &obj) : _it(obj._it) {}
template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator=(const iterator &obj)
{
    if (this != &obj)
        _it = obj._it;
    return (*this);
}
template <typename T>
MutantStack<T>::iterator::~iterator() {}


template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator++()
{
    ++_it;
    return (*this);
}
template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator--()
{
    --_it;
    return (*this);
}
template <typename T>
bool MutantStack<T>::iterator::operator!=(const iterator &obj)
{
    return (_it != obj._it);
}
template <typename T>
T &MutantStack<T>::iterator::operator*()
{
    return (*_it);
}