#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& scf);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& scf);
    ~ShrubberyCreationForm();
};

#endif


// ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees
// inside it.