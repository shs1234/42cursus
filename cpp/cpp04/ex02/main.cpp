#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // const Animal* meta = new Animal(); // 컴파일 애러
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    // meta->makeSound();

    // delete meta;
    delete j;
    delete i;
    
    return 0;
}