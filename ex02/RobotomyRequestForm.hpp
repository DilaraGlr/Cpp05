#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;

    public:
        RobotomyRequestForm(std::string const & target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        ~RobotomyRequestForm();

        RobotomyRequestForm & operator=(RobotomyRequestForm const & src);

        void execute(Bureaucrat const & executor) const;

        std::string getTarget() const;
        
        class RobotomyFailureException : public std::exception
        {
        public:
            const char * what() const throw();
        };
};

#endif