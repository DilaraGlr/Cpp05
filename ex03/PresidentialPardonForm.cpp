#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src), target(src.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
    if (this != &src)
    {
        target = src.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
    return target;
}

const char * PresidentialPardonForm::FileCreationException::what() const throw()
{
    return "Error: could not create the file";
}

std::ostream & operator<<(std::ostream & os, PresidentialPardonForm const & src)
{
    os << src.getName() << " (signed: " << src.getSigned() << ", grade to sign: " << src.getGradeToSign() << ", grade to execute: " << src.getGradeToExec() << ", target: " << src.getTarget() << ")";
    return os;
}
