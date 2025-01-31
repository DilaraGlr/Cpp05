#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* rrf = NULL;

    try
    {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl; // Vérifier que le formulaire est bien créé
        delete rrf; // Ne pas oublier de libérer la mémoire !
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

