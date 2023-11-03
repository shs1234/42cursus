#include "func.hpp"

int main()
{
    Base *bPtr = generate();
    Base &bRef = *bPtr;

    identify(bPtr);
    identify(bRef);

    return (0);
}
