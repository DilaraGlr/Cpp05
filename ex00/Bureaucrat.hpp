#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception> 

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

        // Classes d'exception internes
        class GradeTooHighException : public std::exception
        {
            public:
                const char * what() const throw(); // Hérité de std::exception
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char * what() const throw();
        };
};

// Surcharge de l'opérateur <<
std::ostream & operator<<(std::ostream & os, Bureaucrat const & src);

#endif
