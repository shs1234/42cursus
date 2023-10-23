#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::deque<T>
{
public:
    MutantStack();
    MutantStack(const MutantStack<T> &ms);
    ~MutantStack();
    MutantStack<T> &operator=(const MutantStack<T> &ms);

    void push(T item);
    void pop();
    T top();
};

template <typename T>
MutantStack<T>::MutantStack()
{}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &ms) : std::deque<T>(ms)
{}
template <typename T>
MutantStack<T>::~MutantStack()
{}
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &ms)
{
    if (this != &ms)
        std::deque<T>::operator=(ms);
    return (*this);
}

template <typename T>
void MutantStack<T>::push(T item)
{
    std::deque<T>::push_back(item);
}
template <typename T>
void MutantStack<T>::pop()
{
    std::deque<T>::pop_back();
}
template <typename T>
T MutantStack<T>::top()
{
    return (std::deque<T>::back());
}

#endif
