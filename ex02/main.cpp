#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat bob("Bob", 45);
    ShrubberyCreationForm shrubbery("garden");
    RobotomyRequestForm robotomy("fichier");
    PresidentialPardonForm pardon("Roger");

    std::cout << bob << std::endl;
    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;

    bob.signForm(shrubbery);
    bob.signForm(robotomy);
    bob.signForm(pardon);

    bob.executeForm(shrubbery);
    bob.executeForm(robotomy);
    bob.executeForm(pardon);

    return 0;
}
