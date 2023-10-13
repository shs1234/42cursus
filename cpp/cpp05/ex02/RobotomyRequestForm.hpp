#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& rrf);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& rrf);
    ~RobotomyRequestForm();
};

#endif

// RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed.