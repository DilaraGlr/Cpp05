#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string const & name, int grade)
    : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
    : name(src.name), grade(src.grade)
{
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
    if (this != &src)
        this->grade = src.grade;
    return *this;
}

std::string const & Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade == 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade == 150)
        throw GradeTooLowException();
    grade++;
}

void Bureaucrat::signForm(AForm & form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception & e)
    {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception & e)
    {
        std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream & operator<<(std::ostream & os, Bureaucrat const & src)
{
    os << src.getName() << ", bureaucrat grade " << src.getGrade();
    return os;
}