#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
    std::string const name;
    int grade;

public:
    Bureaucrat(std::string const & name, int grade);
    Bureaucrat(Bureaucrat const & src);
    ~Bureaucrat();

    Bureaucrat & operator=(Bureaucrat const & src);

    std::string const & getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(AForm & form) const;
    void executeForm(AForm const & form) const;

    class GradeTooHighException : public std::exception
    {
    public:
        const char * what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char * what() const throw();
    };
};

std::ostream & operator<<(std::ostream & os, Bureaucrat const & src);

#endif
