#pragma once

#include <iostream>
#include <algorithm>
#include <list>

class Span
{
private:
    unsigned int _max;
    std::list<int> _lst;

    Span();

public:
    Span(unsigned int max);
    Span(const Span& obj);
    ~Span();
    Span &operator=(const Span& obj);

    void addNumber(int n);
    void addNumbers(unsigned int howMany, int num);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    void printVec();

    class ContainerIsFull : public std::exception
    {
        const char *what() const throw();
    };
    class TooFewNumbers : public std::exception
    {
        const char *what() const throw();
    };
};
