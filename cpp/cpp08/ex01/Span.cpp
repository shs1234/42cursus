#include "Span.hpp"

Span::Span() : _curr(0)
{}
Span::Span(unsigned int max) : _curr(0)
{
    _vec.resize(max);
}
Span::Span(const Span& sp) : _curr(sp._curr), _vec(sp._vec)
{}
Span::~Span()
{}
Span &Span::operator=(const Span& sp)
{
    if (this != &sp)
    {
        _curr = sp._curr;
        _vec = sp._vec;
    }
    return (*this);
}

void Span::addNumber(int n)
{
    if (_curr == _vec.size())
        throw ContainerIsFull();
    _vec[_curr] = n;
    _curr++;
}
void Span::addNumbers(unsigned int howMany, int num)
{
    if (_vec.size() < _curr + howMany)
        throw ContainerIsFull();
    std::vector<int>::iterator it = _vec.begin() + _curr;
    std::vector<int>::iterator it_end = it + howMany;
    std::fill(it, it_end, num);
    _curr += howMany;
}

unsigned int Span::shortestSpan()
{
    if (_curr <= 1)
        throw TooFewNumbers();
    std::sort(_vec.begin(), _vec.begin() + _curr);
    unsigned int span = _vec[1] - _vec[0];
    for (unsigned int i = 1; i < _curr && span != 0; i++)
    {
        if (static_cast<unsigned int>(_vec[i] - _vec[i - 1]) < span)
            span = _vec[i] - _vec[i - 1];
    }
    return (span);
}
unsigned int Span::longestSpan()
{
    if (_curr <= 1)
        throw TooFewNumbers();
    std::sort(_vec.begin(), _vec.begin() + _curr);
    return (_vec[_curr - 1] - _vec[0]);
}
void Span::printVec()
{
    std::vector<int>::iterator it = _vec.begin();
    std::vector<int>::iterator it_end = it + _curr;
    for (; it != it_end; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

const char *Span::ContainerIsFull::what() const throw()
{
    return ("Container is full");
}
const char *Span::TooFewNumbers::what() const throw()
{
    return ("Too few numbers");
}
