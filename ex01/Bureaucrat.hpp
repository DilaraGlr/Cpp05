#ifndef EB77C550_B5EC_43A6_A4F0_FC908F9EC013
#define EB77C550_B5EC_43A6_A4F0_FC908F9EC013
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception> // Nécessaire pour std::exception

class Bureaucrat
{
    private:
        std::string const name; // Nom constant
        int grade;              // Grade du bureaucrate

    public:
        // Constructeurs et destructeur
        Bureaucrat(std::string const & name, int grade);
        Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat();

        // Opérateur d'affectation
        Bureaucrat & operator=(Bureaucrat const & src);

        // Getters
        std::string const & getName() const;
        int getGrade() const;

        // Méthodes pour modifier le grade
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


#endif /* EB77C550_B5EC_43A6_A4F0_FC908F9EC013 */
