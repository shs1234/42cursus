#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <exception>
#include <sstream>

class RPN
{
private:
    std::string _rpn;
    std::stack<int> _st;

    RPN();

public:
    RPN(std::string rpn);
    RPN(const RPN& r);
    RPN& operator=(const RPN& r);
    ~RPN();

    void calc();

    class Error : public std::exception
    {
        const char *what() const throw();
    };
    class DivideByZero : public std::exception
    {
        const char *what() const throw();
    };
};

#endif
