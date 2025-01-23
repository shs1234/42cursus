#include "Span.hpp"

int	main(void)
{
    try
    {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------------------" << std::endl;
    try
    {
        Span sp = Span(10);

        sp.addNumber(6);
        sp.addNumber(11);
        sp.addNumber(3);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        sp.addNumbers(5, 1);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        sp.printVec();
        sp.addNumbers(3, 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
	return (0);
}
