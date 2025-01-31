#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Constructeur prenant un target
ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

// Constructeur par copie
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
    : AForm(src), target(src.target) {}

// Destructeur
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Opérateur d'affectation
ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
    if (this != &src)
        target = src.target;
    return *this;
}

// Implémentation de execute()
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor); // Vérifie que le formulaire est signé et que le grade est suffisant

    std::ofstream file((target + "_shrubbery").c_str());
    if (!file)
        throw FileCreationException();

    file << "       _-_\n"
            "    /~~   ~~\\\n"
            " /~~         ~~\\\n"
            "{               }\n"
            " \\  _-     -_  /\n"
            "   ~  \\\\ //  ~\n"
            "_- -   | | _- _\n"
            "  _ -  | |   -_\n"
            "      // \\\\\n";

    file.close();
}

// Exception pour erreur de création de fichier
const char * ShrubberyCreationForm::FileCreationException::what() const throw()
{
    return "Error: could not create the file";
}

// Accesseur pour target
std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}

// Surcharge de l'opérateur <<
std::ostream & operator<<(std::ostream & os, ShrubberyCreationForm const & src)
{
    os << src.getName() << " (signed: " << src.getSigned()
       << ", grade to sign: " << src.getGradeToSign()
       << ", grade to execute: " << src.getGradeToExec()
       << ", target: " << src.getTarget() << ")";
    return os;
}
