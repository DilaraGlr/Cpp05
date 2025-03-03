#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <algorithm> 
#include <cctype>

class Intern
{
    public:
        Intern();
        Intern(const Intern &src);
        ~Intern();
        Intern &operator=(const Intern &src);

        AForm *makeForm(std::string formName, std::string target);
};

#endif
