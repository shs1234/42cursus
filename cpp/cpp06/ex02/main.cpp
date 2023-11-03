#include "func.hpp"

int main()
{
    Base *bPtr;

    bPtr = generate();
    identify(bPtr);

    Base &bRef = *bPtr;
    identify(bRef);

    return (0);
}
