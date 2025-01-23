#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
    typedef struct
    {
        std::string name;
        AForm *(Intern::*func)(std::string);
    }formList;
    AForm *createPresidentialPardonForm(std::string target);
    AForm *createRobotomyRequestForm(std::string target);
    AForm *createShrubberyCreationForm(std::string target);
    
public:
    Intern();
    Intern(const Intern& it);
    Intern& operator=(const Intern& it);
    ~Intern();

    AForm *makeForm(std::string formName, std::string target);
    
    class InvalidFormName : public std::exception
    {
        const char* what() const throw();
    };
};

#endif
