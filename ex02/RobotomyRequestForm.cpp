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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor); // Vérifie si le bureaucrate peut exécuter
    std::cout << "* drilling noises *" << std::endl;

    // Utilisation d'un compteur statique
    static int counter = 0;
    counter++;

    if (counter % 2 == 0) // Alterne entre succès et échec
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        throw RobotomyFailureException();
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
