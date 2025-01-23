#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;

    ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& scf);
    
public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& scf);
    virtual ~ShrubberyCreationForm();

    virtual void execute(Bureaucrat const& executor) const;

    class FileOpenFail : public std::exception
    {
        const char* what() const throw();
    };
};

#endif
