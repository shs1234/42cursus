#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
    delete this->brain;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    this->brain = new Brain(*dog.brain);
}

Dog& Dog::operator=(const Dog& dog)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this == &dog)
        return (*this);
    this->type = dog.type;
    this->brain = new Brain(*dog.brain);
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << this->type << " : mung! mung!" << std::endl;
}

std::string Dog::getType() const
{
    return (this->type);
}

void Dog::setbrain()
{
    this->brain->setideas();
}
void Dog::printbrain()
{
    this->brain->printideas();
}