#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SCF", 0, 145, 137), target("")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCF", 0, 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& scf) : AForm(scf), target(scf.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& scf)
{
    (void)scf;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const char* ShrubberyCreationForm::FileOpenFail::what() const throw()
{
	return ("File Open Fail");
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (this->getIssigned() == 0)
        throw NotSigned();
    if (this->getGradetoexec() < executor.getGrade())
        throw GradeTooLowException();
    std::string asciiTree =
        "   *\n"
        "  ***\n"
        " *****\n"
        "*******\n"
        "  ***\n"
        "  ***\n";
    std::string filename = this->target + "_shrubbery";
    std::ofstream outFile(filename.c_str());
    if (!outFile)
        throw FileOpenFail();
    outFile << asciiTree;
    outFile.close();
}
