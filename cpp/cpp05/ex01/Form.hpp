#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string   name;
    bool                issigned;
    const int           gradetosign;
    const int           gradetoexec;
    Form();
    Form& operator=(const Form& form);

    class GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        const char* what() const throw();
    };
    class AlreadySigned : public std::exception
    {
        const char* what() const throw();
    };
    int gradeCheck(int grade) const;

public:
    Form(std::string name, bool issigned, const int gradetosign, const int gradetoexec);
    Form(const Form& form);
    ~Form();

    void beSigned(const Bureaucrat& b);

    const std::string &getName() const;
    bool getIssigned() const;
    int getGradetosign() const;
    int getGradetoexec() const;
};

std::ostream& operator<<(std::ostream &cout, const Form& form);

#endif
