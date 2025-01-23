#include "Form.hpp"
#include "Bureaucrat.hpp"

int Form::gradeCheck(int grade) const
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    return (grade);
}

Form::Form() : name("noname"), issigned(0), gradetosign(1), gradetoexec(1) {}

Form::Form(std::string name, bool issigned, const int gradetosign, const int gradetoexec)
: name(name), issigned(issigned), gradetosign(gradeCheck(gradetosign)), gradetoexec(gradeCheck(gradetoexec)) {}

Form::Form(const Form& form)
: name(form.name), issigned(form.issigned), gradetosign(form.gradetosign), gradetoexec(form.gradetoexec) {}

Form& Form::operator=(const Form& form)
{
    if (this != &form)
        this->issigned = form.issigned;
    return (*this);
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat& b)
{
    if (this->getIssigned())
        throw AlreadySigned();
    if (b.getGrade() > this->gradetosign)
        throw GradeTooLowException();
    this->issigned = 1;
    std::cout << b.getName() << " signed " << this->getName() << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");
}

const char* Form::AlreadySigned::what() const throw()
{
    return ("Already Signed");
}

const std::string &Form::getName() const
{
    return (this->name);
}
bool Form::getIssigned() const
{
    return (this->issigned);
}
int Form::getGradetosign() const
{
    return (this->gradetosign);
}
int Form::getGradetoexec() const
{
    return (this->gradetoexec);
}

std::ostream& operator<<(std::ostream &cout, const Form& form)
{
    cout << "Form name      : " << form.getName() << std::endl;
    cout << "Is signed      : " << form.getIssigned() << std::endl;
    cout << "Grade to sign  : " << form.getGradetosign() << std::endl;
    cout << "Grade to exec  : " << form.getGradetoexec() << std::endl;
    return (cout);
}