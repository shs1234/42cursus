#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    this->brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog& dog)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    this->type = dog.type;
    this->brain = new Brain(*dog.brain);
}

Dog& Dog::operator=(const Dog& dog)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &dog)
    {
        delete this->brain;
        this->brain = new Brain(*dog.brain);
        this->type = dog.type;
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << this->type << " : mung! mung!" << std::endl;
}

const std::string& Dog::getType() const
{
    return (this->type);
}

void Dog::setbrain() const
{
    this->brain->setideas();
}
void Dog::printbrain() const
{
    this->brain->printideas();
}