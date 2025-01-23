#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string target;

    PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm& ppf);
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& ppf);
    virtual ~PresidentialPardonForm();

    virtual void execute(Bureaucrat const& executor) const;
};

#endif
