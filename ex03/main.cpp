#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
   	Bureaucrat	bureaucrat = Bureaucrat("bureaucrat", 1);

	Intern	intern = Intern();

	AForm	*f1 = intern.makeForm("Shrubbery CreAtion", "Tester");
	AForm	*f2 = intern.makeForm("Robotomy Request", "Tester2");
	AForm	*f3 = intern.makeForm("Presidential Pardon", "Tester3");
	std::cout << std::endl;

	bureaucrat.executeForm(*f1);
	bureaucrat.signForm(*f1);
	bureaucrat.executeForm(*f1);
	std::cout << std::endl;

	bureaucrat.signForm(*f2);
	bureaucrat.executeForm(*f2);
	std::cout << std::endl;

	bureaucrat.signForm(*f3);
	bureaucrat.executeForm(*f3);
	std::cout << std::endl;

	AForm *f4 = intern.makeForm("B-36", "RIP");

	delete f1;
	delete f2;
	delete f3;
	delete f4;
	return 0;

}

