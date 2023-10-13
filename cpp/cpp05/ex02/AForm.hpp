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
    AForm();

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
    AForm(std::string name, bool issigned, const int gradetosign, const int gradetoexec);
    AForm(const AForm& aform);
    AForm& operator=(const AForm& aform);
    virtual ~AForm();

    void beSigned(const Bureaucrat& b);

    virtual const std::string &getName() const = 0;
    bool getIssigned() const;
    int getGradetosign() const;
    int getGradetoexec() const;
};

std::ostream& operator<<(std::ostream &cout, const AForm& aform);

#endif
