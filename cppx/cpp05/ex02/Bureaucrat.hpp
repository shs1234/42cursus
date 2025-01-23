#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat
{
private:
    const std::string name;
    int grade;
    Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& b);
    class GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        const char* what() const throw();
    };
    
public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& b);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;

    void increaseGrade();
    void decreaseGrade();

    void signForm(AForm& aform);
    void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream &cout, const Bureaucrat& b);

#endif
