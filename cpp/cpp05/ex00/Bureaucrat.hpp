#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
    const std::string name;
    int grade;
    Bureaucrat();

    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };

public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& b);
    Bureaucrat& operator=(const Bureaucrat& b);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;

    void increaseGrade();
    void decreaseGrade();
};

std::ostream& operator<<(std::ostream &cout, const Bureaucrat& b);

#endif
