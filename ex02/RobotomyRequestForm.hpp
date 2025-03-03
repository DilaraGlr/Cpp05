#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
# include <ctime>
# include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
        void exec(void) const;

    public:
        RobotomyRequestForm(std::string const & target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        ~RobotomyRequestForm();

        RobotomyRequestForm & operator=(RobotomyRequestForm const & src);


        std::string getTarget() const;
        
        class RobotomyFailureException : public std::exception
        {
        public:
            const char * what() const throw();
        };
};

#endif