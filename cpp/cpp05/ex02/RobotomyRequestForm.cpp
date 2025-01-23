#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RRF", 0, 72, 45), target("")
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RRF", 0, 72, 45), target(target)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rrf) : AForm(rrf), target(rrf.target)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rrf)
{
    (void)rrf;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (this->getIssigned() == 0)
        throw NotSigned();
    if (this->getGradetoexec() < executor.getGrade())
        throw GradeTooLowException();
    std::cout << "*SOME DRILLING NOISES* " << this->target;
    if (std::rand() < RAND_MAX / 2)
        std::cout << " has been robotomized" << std::endl;
    else
        std::cout << " robotomy failed" << std::endl;
}
