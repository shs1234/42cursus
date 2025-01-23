#include "AForm.hpp"
#include "Bureaucrat.hpp"

int AForm::gradeCheck(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}

AForm::AForm() : name("noname"), issigned(0), gradetosign(1), gradetoexec(1) {}

AForm::AForm(std::string name, bool issigned, const int gradetosign, const int gradetoexec)
: name(name), issigned(issigned), gradetosign(gradeCheck(gradetosign)), gradetoexec(gradeCheck(gradetoexec)) {}

AForm::AForm(const AForm& aform)
: name(aform.name), issigned(aform.issigned), gradetosign(aform.gradetosign), gradetoexec(aform.gradetoexec) {}

AForm& AForm::operator=(const AForm& aform)
{
	(void)aform;
	return (*this);
}

AForm::~AForm() {}

void AForm::beSigned(const Bureaucrat& b)
{
	if (this->getIssigned())
		throw AlreadySigned();
	if (b.getGrade() > this->gradetosign)
		throw GradeTooLowException();
	this->issigned = 1;
	std::cout << b.getName() << " signed " << this->getName() << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}
const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}
const char* AForm::AlreadySigned::what() const throw()
{
	return ("Already Signed");
}
const char* AForm::NotSigned::what() const throw()
{
	return ("Not Signed");
}

const std::string &AForm::getName() const
{
	return (this->name);
}
bool AForm::getIssigned() const
{
	return (this->issigned);
}
int AForm::getGradetosign() const
{
	return (this->gradetosign);
}
int AForm::getGradetoexec() const
{
	return (this->gradetoexec);
}

std::ostream& operator<<(std::ostream &cout, const AForm& aform)
{
	cout << "AForm name		: " << aform.getName() << std::endl;
	cout << "Is signed		: " << aform.getIssigned() << std::endl;
	cout << "Grade to sign	: " << aform.getGradetosign() << std::endl;
	cout << "Grade to exec	: " << aform.getGradetoexec() << std::endl;
	return (cout);
}
