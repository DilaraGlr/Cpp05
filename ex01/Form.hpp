#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception> 

class Bureaucrat; // Pré-déclaration de Bureaucrat

class Form
{
private:
    std::string const name; // Nom constant
    bool signedStatus;      // Indique si le formulaire est signé
    int const gradeToSign;  // Grade nécessaire pour signer le formulaire
    int const gradeToExec;  // Grade nécessaire pour exécuter le formulaire

public:
    // Constructeurs et destructeur
    Form(std::string const & name, int gradeToSign, int gradeToExec);
    Form(Form const & src);
    ~Form();

    // Opérateur d'affectation
    Form & operator=(Form const & src);

    // Getters
    std::string const & getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;

    // Méthodes pour signer et exécuter le formulaire
    void beSigned(Bureaucrat const & src);
    void execute(Bureaucrat const & executor) const;

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
std::ostream & operator<<(std::ostream & os, Form const & src);

#endif