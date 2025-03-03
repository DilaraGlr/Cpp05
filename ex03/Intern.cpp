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

AForm *makePresidentialForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

static AForm *makeRobotForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm *makeShruberryForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *formToCreate = NULL;
	AForm *(*allForm[])(std::string) = {&makePresidentialForm, &makeRobotForm, &makeShruberryForm};
	std::string form[] = {"presidential pardon", "shrubbery creation", "robotomy request"};
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);

	for(int i =0; i < 3; i++)
	{
		if (!name.compare(form[i]))
		{
			formToCreate = allForm[i](target);
			break;
		}
	}

	if (!formToCreate)
		std::cout << "Form : "<< name << " doesn't exist" << std::endl;
	else
		std::cout << "Intern creates " << formToCreate->getName() << std::endl;
	
	return formToCreate;
}