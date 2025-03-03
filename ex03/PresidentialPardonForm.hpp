#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
        void exec(void) const;

    public:
        PresidentialPardonForm(std::string const & target);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        ~PresidentialPardonForm();

        PresidentialPardonForm & operator=(PresidentialPardonForm const & src);


        std::string getTarget() const;

        class FileCreationException : public std::exception
        {
        public:
            const char * what() const throw();
        };
};

#endif