#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade)
: name(name)
{
    // 1~150 예외처리
    if (grade < 1)
        throw GradeTooHighException();
    else if(grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b)
: name(b.name), grade(b.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
    if (this != &b)
        this->grade = b.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const
{
    return (this->name);
}
int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::increaseGrade()
{
    // 1 예외처리
    this->grade--;
}
void Bureaucrat::decreaseGrade()
{
    // 150 예외처리
    this->grade++;
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");
}

std::ostream& operator<<(std::ostream &cout, const Bureaucrat& b)
{
    cout << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (cout);
}
