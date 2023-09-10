#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // test1
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    // test2
    Animal *ani[4];
    std::cout << std::endl;

    for (int i = 0; i < 2; i++)
    {
        ani[i] = new Dog();
        std::cout << std::endl;
    }
    for (int i = 2; i < 4; i++)
    {
        ani[i] = new Cat();
        std::cout << std::endl;
    }
    for (int i = 0; i < 4; i++)
        delete ani[i];

    // test3
    Dog *dog1 = new Dog();
    Dog *dog2 = new Dog(*dog1);

    dog1->setbrain();
    dog1->printbrain();
    dog2->printbrain();

    delete dog1;
    delete dog2;

    return 0;
}