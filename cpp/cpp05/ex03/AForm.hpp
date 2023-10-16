#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string   name;
    bool                issigned;
    const int           gradetosign;
    const int           gradetoexec;
    AForm& operator=(const AForm& aform);
    int gradeCheck(int grade) const;
    AForm();

public:
    AForm(std::string name, bool issigned, const int gradetosign, const int gradetoexec);
    AForm(const AForm& aform);
    virtual ~AForm();

    const std::string &getName() const;
    bool getIssigned() const;
    int getGradetosign() const;
    int getGradetoexec() const;

    void beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const& executor) const = 0;

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
    class NotSigned : public std::exception
    {
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream &cout, const AForm& aform);

#endif
