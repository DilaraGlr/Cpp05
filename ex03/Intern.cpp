#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src)
{
    *this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &src)
{
    (void)src;
    return *this;
}

const char *Intern::UnknownFormException::what() const throw()
{
    return "Error: Unknown form request!";
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    std::string formNames[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };

    AForm *forms[3] = {
        new PresidentialPardonForm(target),
        new RobotomyRequestForm(target),
        new ShrubberyCreationForm(target)
    };

    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            // Supprimer les formulaires inutilisés
            for (int j = 0; j < 3; j++)
            {
                if (j != i)
                    delete forms[j];
            }
            return forms[i];
        }
    }

    // Supprimer tous les formulaires si aucun ne correspond
    for (int j = 0; j < 3; j++)
        delete forms[j];

    throw UnknownFormException();
}
