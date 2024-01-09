#include "Span.hpp"

Span::Span()
{}
Span::Span(unsigned int max) : _max(max)
{}
Span::Span(const Span& obj) : _max(obj._max), _lst(obj._lst)
{}
Span::~Span()
{}
Span &Span::operator=(const Span& obj)
{
    if (this != &obj)
    {
        _max = obj._max;
        _lst = obj._lst;
    }
    return (*this);
}

void Span::addNumber(int n)
{
    if (_lst.size() == _max)
        throw ContainerIsFull();
    _lst.push_back(n);
}
void Span::addNumbers(unsigned int howMany, int num)
{
    long long tmp = 0;
    tmp += _lst.size();
    tmp += howMany;
    if (_max < tmp)
        throw ContainerIsFull();

    std::list<int> toadd(howMany, num);
    _lst.insert(_lst.end(), toadd.begin(), toadd.end());
}

unsigned int Span::shortestSpan()
{
    if (_lst.size() <= 1)
        throw TooFewNumbers();
    _lst.sort();
    std::list<int>::iterator it = _lst.begin();
    std::list<int>::iterator it2 = _lst.begin();
    it2++;
    unsigned int span = *it2 - *it;
    for (unsigned int i = 1; i < _lst.size() && span != 0; i++)
    {
        if (static_cast<unsigned int>(*it2 - *it) < span) //static_cast<unsigned int> 필요한가?
            span = static_cast<unsigned int>(*it2 - *it);
        it++;
        it2++;
    }
    return (span);
}

unsigned int Span::longestSpan()
{
    if (_lst.size() <= 1)
        throw TooFewNumbers();
    _lst.sort();
    return (_lst.back() - _lst.front());
}
void Span::printVec()
{
    std::list<int>::iterator it = _lst.begin();
    for (; it != _lst.end(); ++it)
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
