#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        std::string const name; // Nom constant
        bool signedStatus;      // Indique si le formulaire est signé
        int const gradeToSign;  // Grade nécessaire pour signer le formulaire
        int const gradeToExec;  // Grade nécessaire pour exécuter le formulaire
        virtual void exec() const = 0;


    public:
        
        // Constructeurs et destructeur
        AForm(std::string const & name, int gradeToSign, int gradeToExec);
        AForm(AForm const & src);
        virtual ~AForm();

        
        // Opérateur d'affectation
        AForm & operator=(AForm const & src);

        
        // Getters
        std::string const & getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        void		execute(Bureaucrat const & executor) const;

        
        // Méthodes pour signer et exécuter le formulaire
        void beSigned(Bureaucrat const & src);

        
        // Classes d'exception internes
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

        class FormNotSignedException : public std::exception
        {
        public:
            const char * what() const throw();
        };

        class GradeTooLowToExecException : public std::exception
        {
        public:
            const char * what() const throw();
        };
};

// Surcharge de l'opérateur <<
std::ostream & operator<<(std::ostream & os, AForm const & src);

#endif
