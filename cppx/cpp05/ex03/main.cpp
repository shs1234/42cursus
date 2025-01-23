#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;
    AForm *form;
    try
    {
        Bureaucrat b("hoseoson", 6);
        form = intern.makeForm("PresidentialPardonForm", "target");
        b.signForm(*form);
        b.executeForm(*form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete form;
    return (0);
}
