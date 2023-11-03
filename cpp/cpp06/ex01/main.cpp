#include "Serializer.hpp"

int main()
{
    Data d;
    Data *d2;
    uintptr_t ret;
    
    ret = Serializer::serialize(&d);
    d2 = Serializer::deserialize(ret);

    if (&d == d2)
        std::cout << "same" << std::endl;
    else
        std::cout << "not same" << std::endl;
    return (0);
}
