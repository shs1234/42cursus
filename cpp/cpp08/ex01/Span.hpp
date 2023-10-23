#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
    unsigned int _curr;
    std::vector<int> _vec;
    Span();

public:
    Span(unsigned int max);
    Span(const Span& sp);
    ~Span();
    Span &operator=(const Span& sp);

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

#endif
