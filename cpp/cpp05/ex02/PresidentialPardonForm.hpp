#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:

public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& ppf);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& ppf);
    ~PresidentialPardonForm();
};

#endif

// PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.