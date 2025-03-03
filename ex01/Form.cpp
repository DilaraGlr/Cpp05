#include "Form.hpp"
#include "Bureaucrat.hpp" 

Form::Form(std::string const & name, int gradeToSign, int gradeToExec)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const & src)
    : name(src.name), signedStatus(src.signedStatus), gradeToSign(src.gradeToSign), gradeToExec(src.gradeToExec)
{
}

Form::~Form() {}

Form & Form::operator=(Form const & src)
{
    if (this != &src)
    {
        signedStatus = src.signedStatus;
    }
    return *this;
}

std::string const & Form::getName() const
{
    return name;
}

bool Form::getSigned() const
{
    return signedStatus;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExec() const
{
    return gradeToExec;
}

void Form::beSigned(Bureaucrat const & src)
{
    if (src.getGrade() > gradeToSign)
        throw Form::GradeTooLowException();
    signedStatus = true;
}


const char * Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char * Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char * Form::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

const char * Form::GradeTooLowToExecException::what() const throw()
{
    return "Grade is too low to execute the form";
}

std::ostream & operator<<(std::ostream & os, Form const & src)
{
    os << "Form " << src.getName() << " is " << (src.getSigned() ? "signed" : "not signed")
       << ", grade to sign: " << src.getGradeToSign() 
       << ", grade to execute: " << src.getGradeToExec();
    return os;
}