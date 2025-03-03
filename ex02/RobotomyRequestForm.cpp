#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) 
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) 
    : AForm(src), target(src.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
    if (this != &src)
    {
        AForm::operator=(src); // Copie aussi les attributs de AForm
        target = src.target;
    }
    return *this;
}

void RobotomyRequestForm::exec(void) const
{
    std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << this->target << " has been robotomized" << std::endl;
	else
		std::cout << this->target << " robotomy failed" << std::endl;
}

const char * RobotomyRequestForm::RobotomyFailureException::what() const throw()
{
    return "Error: robotomization failed";
}

std::string RobotomyRequestForm::getTarget() const
{
    return target;
}

std::ostream & operator<<(std::ostream & os, RobotomyRequestForm const & src)
{
    os << src.getName() << " (signed: " << src.getSigned()
       << ", grade to sign: " << src.getGradeToSign()
       << ", grade to execute: " << src.getGradeToExec()
       << ", target: " << src.getTarget() << ")";
    return os;
}
