#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
    std::string target;

    RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& rrf);
    
public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& rrf);
    virtual ~RobotomyRequestForm();

    virtual void execute(Bureaucrat const& executor) const;
};

#endif
