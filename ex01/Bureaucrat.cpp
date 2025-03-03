#include "Bureaucrat.hpp"

// Constructeur principal
Bureaucrat::Bureaucrat(std::string const & name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

// Constructeur par copie
Bureaucrat::Bureaucrat(Bureaucrat const & src) : name(src.name), grade(src.grade)
{
}

// Destructeur
Bureaucrat::~Bureaucrat()
{
}

// Opérateur d'affectation
Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
    if (this != &src) // Évite l'auto-affectation
    {
        this->grade = src.grade; // Seul le grade peut être copié
    }
    return *this;
}

// Getters
std::string const & Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

// Méthodes pour modifier le grade
void Bureaucrat::incrementGrade()
{
    if (grade <= 1) // Limite supérieure atteinte
        throw GradeTooHighException();
    --grade;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150) // Limite inférieure atteinte
        throw GradeTooLowException();
    ++grade;
}

void Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(Form::GradeTooLowException & e)
	{
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
	
}

// Implémentation des classes d'exception
const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

// Surcharge de l'opérateur <<
std::ostream & operator<<(std::ostream & os, Bureaucrat const & src)
{
    os << src.getName() << ", bureaucrat grade " << src.getGrade();
    return os;
}
