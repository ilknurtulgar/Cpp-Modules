# include "Intern.hpp"
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        Bureaucrat b1("bob",1);

        rrf = someRandomIntern.makeForm("robotomy request", "tree");
        b1.signForm(*rrf);
        b1.executeForm(*rrf);

        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
