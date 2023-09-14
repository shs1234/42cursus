#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::Bureaucrat(std::string name, int grade)
: name(name), grade(grade)
{
    // grade 예외처리
}
Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
: name(bureaucrat.name), grade(bureaucrat.grade)
{
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
    if (this == &bureaucrat)
        return (*this);
    this->grade = bureaucrat.grade;
}
Bureaucrat::~Bureaucrat()
{

}

void Bureaucrat::getName() const
{

}
void Bureaucrat::getGrade()
{

}

void Bureaucrat::increment()
{

}
void Bureaucrat::decrement()
{

}