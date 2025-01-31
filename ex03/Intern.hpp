#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &src);
        ~Intern();
        Intern &operator=(const Intern &src);

        AForm *makeForm(std::string formName, std::string target);

        class UnknownFormException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif
