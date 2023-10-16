#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PPF", 0, 25, 5), target("")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF", 0, 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ppf) : AForm(ppf), target(ppf.target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ppf)
{
    (void)ppf;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (this->getIssigned() == 0)
        throw NotSigned();
    if (this->getGradetoexec() < executor.getGrade())
        throw GradeTooLowException();
    
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
