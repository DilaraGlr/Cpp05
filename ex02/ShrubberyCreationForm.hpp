#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target; 
        void exec(void) const;

    public:
        ShrubberyCreationForm(std::string const & target);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);

        std::string getTarget() const;

        class FileCreationException : public std::exception
        {
        public:
            const char * what() const throw();
        };
};

// Surcharge de l'opérateur <<
std::ostream & operator<<(std::ostream & os, ShrubberyCreationForm const & src);

#endif  
