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
    std::cout << std::endl;

    // test3
    Dog *dog1 = new Dog();
    Dog *dog2 = new Dog(*dog1);
    Dog *dog3 = new Dog;
    dog1->setbrain();
    dog1->printbrain();
    dog2->printbrain();
    *dog3 = *dog1;
    dog3->printbrain();

    std::cout << std::endl;
    delete dog1;
    delete dog2;
    delete dog3;

    return 0;
}