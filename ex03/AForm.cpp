#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string const & name, int gradeToSign, int gradeToExec)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & src)
    : name(src.name), signedStatus(src.signedStatus), gradeToSign(src.gradeToSign), gradeToExec(src.gradeToExec)
{
}

AForm::~AForm() {}

AForm & AForm::operator=(AForm const & src)
{
    if (this != &src)
    {
        signedStatus = src.signedStatus; 
    }
    return *this;
}

std::string const & AForm::getName() const
{
    return name;
}

bool AForm::getSigned() const
{
    return signedStatus;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExec() const
{
    return gradeToExec;
}

void AForm::beSigned(Bureaucrat const & src)
{
    if (src.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    signedStatus = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
   if(executor.getGrade() > this->gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	else if (!this->signedStatus)
		throw AForm::FormNotSignedException();
	else
		this->exec();
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char * AForm::FormNotSignedException::what() const throw()
{
    return "AForm is not signed";
}

const char * AForm::GradeTooLowToExecException::what() const throw()
{
    return "Grade is too low to execute the Aform";
}

std::ostream & operator<<(std::ostream & os, AForm const & src)
{
    os << "AForm " << src.getName() << " is " << (src.getSigned() ? "signed" : "not signed")
       << ", grade to sign: " << src.getGradeToSign()
       << ", grade to execute: " << src.getGradeToExec();
    return os;
}
