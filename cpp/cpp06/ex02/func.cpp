#include "func.hpp"

Base *generate(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    switch (std::rand() % 3)
    {
    case 0 :
        return (new A);
    case 1 :
        return (new B);
    case 2 :
        return (new C);
    }
    return (NULL);
}
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
}
