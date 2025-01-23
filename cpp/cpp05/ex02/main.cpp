#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    AForm *form1 = new ShrubberyCreationForm("target");
    AForm *form2 = new RobotomyRequestForm("target");
    AForm *form3 = new PresidentialPardonForm("target");
    try
    {
        Bureaucrat b("hoseoson", 6);
        b.signForm(*form1);
        b.executeForm(*form1);
        b.signForm(*form2);
        form2->execute(b);
        b.executeForm(*form2);
        b.signForm(*form3);
        form3->execute(b);
        b.executeForm(*form3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete form1;
    delete form2;
    delete form3;
    return (0);
}
