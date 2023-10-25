#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(std::string rpn) : _rpn(rpn) {}
RPN::RPN(const RPN& r)
{
    _rpn = r._rpn;
    _st = r._st;
}
RPN& RPN::operator=(const RPN& r)
{
    if (this != &r)
    {
        _st.empty();
        _rpn = r._rpn;
        _st = r._st;
    }
    return (*this);
}
RPN::~RPN() {}

void RPN::calc()
{
    int left;
    int right;
    for (std::size_t i = 0; i < _rpn.size(); i++)
    {
        if (i % 2 == 0)
        {
            if (isdigit(_rpn[i]))
                _st.push(_rpn[i] - '0');
            else if (_rpn[i] == '+' || _rpn[i] == '-' || _rpn[i] == '*' || _rpn[i] == '/')
            {
                if (_st.size() < 2)
                    throw Error();
                right = _st.top();
                _st.pop();
                left = _st.top();
                _st.pop();
                if (_rpn[i] == '+')
                    _st.push(left + right);
                else if (_rpn[i] == '-')
                    _st.push(left - right);
                else if (_rpn[i] == '*')
                    _st.push(left * right);
                else if (_rpn[i] == '/')
                {
                    if (right == 0)
                        throw DivideByZero();
                    _st.push(left / right);
                }
            }
            else
                throw Error();
        }
        else
        {
            if (_rpn[i] != ' ' || i + 1 == _rpn.size())
                throw Error();
        }
    }
    if (_st.size() != 1)
        throw Error();
    std::cout << _st.top() << std::endl;
}

const char *RPN::Error::what() const throw()
{
    return ("Error");
}
const char *RPN::DivideByZero::what() const throw()
{
    return ("Error : Divide By Zero");
}
