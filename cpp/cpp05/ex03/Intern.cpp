#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& it)
{
    (void)it;
}

Intern& Intern::operator=(const Intern& it)
{
    (void)it;
    return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::createPresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}
AForm *Intern::createRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}
AForm *Intern::createShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    formList fl[3];
    fl[0].name = "PresidentialPardonForm";
    fl[0].func = &Intern::createPresidentialPardonForm;
    fl[1].name = "RobotomyRequestForm";
    fl[1].func = &Intern::createRobotomyRequestForm;
    fl[2].name = "ShrubberyCreationForm";
    fl[2].func = &Intern::createShrubberyCreationForm;
    for (int i = 0; i < 3; i++)
    {
        if (formName == fl[i].name)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return ((this->*fl[i].func)(target));
        }
    }
    throw InvalidFormName();
}

const char* Intern::InvalidFormName::what() const throw()
{
	return ("Invalid Form Name");
}