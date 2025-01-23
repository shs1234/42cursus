#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    this->brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat& cat)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    this->type = cat.type;
    this->brain = new Brain(*cat.brain);
}

Cat& Cat::operator=(const Cat& cat)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &cat)
    {
        delete this->brain;
        this->brain = new Brain(*cat.brain);
        this->type = cat.type;
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << this->type << " : yaong" << std::endl;
}

const std::string& Cat::getType() const
{
    return (this->type);
}

void Cat::setbrain() const
{
    this->brain->setideas();
}
void Cat::printbrain() const
{
    this->brain->printideas();
}
