#include "Bureaucrat.hpp"
#include "Intern.hpp"

# define CL "\033[1m\033[36m"
# define RS "\033[0m"
int main()
{
	Intern one;
	Form *form;
	int count = 15;
	std::string type[15] = 
	{"RobotomyRequestFOrm",
	"robotomy request",
	"robotomyrequest",
	"robotomy request",
	"Roboto Myrequest",
	"roboto my request form",
	"Presidential pardon",
	"PresidentialPardonForm",
	"presidential pardon form",
	"Presidential Pardon",
	"ShrubberyCreationForm", 
	"shrubbery creation", 
	"shrubbery creation form", 
	"ShrubberyCreation", 
	"shrubberycreationform"};
	
	for (int i = 0; i < count ; i++)
	{
		std::cout << CL << "------------------------------------------\n" << RS;
		std::cout << CL << " Trying to make : " << type[i] << "\n" << RS;
		std::cout << CL << "------------------------------------------\n" << RS;
		try
		{
			form = one.makeForm(type[i], "TARGET");
			delete form;
		}
		catch (Intern::NotFound &err)
		{
			std::cout << type[i] << " has error\n";
		}
	}
	
	std::cout << "\033[31m" << "=================================\n" << RS;
	std::cout << "\033[31m" << "|                               |\n" << RS;
	std::cout << "\033[31m" << "=================================\n" << RS;
	std::string errtype[5] = 
			{"Myform", "New Form", "Shurbery","Presidetial","Robot"};
		
	for (int i = 0; i < 5 ; i++)
	{
		std::cout << CL << "------------------------------------------\n" << RS;
		std::cout << CL << " Trying to make : " << errtype[i] << "\n" << RS;
		std::cout << CL << "------------------------------------------\n" << RS;
		try
		{
			form = one.makeForm(errtype[i], "TARGET");
			delete form;
		}
		catch (Intern::NotFound &err)
		{
			std::cout << errtype[i] << " has error, because of " << err.what();
			std::cout << std::endl;
		}
	}
	
	std::cout << "\033[31m" << "=================================\n" << RS;
	std::cout << "\033[31m" << "|                               |\n" << RS;
	std::cout << "\033[31m" << "=================================\n" << RS;
	
	Intern someIntern;
	Bureaucrat supervisor("Supervisor", 1);
	Bureaucrat francis("Francis", 25);
	std::cout << supervisor;
	std::cout << francis;
	
	std::cout << CL << "-------------------\n" << RS;
	Form *shrub = someIntern.makeForm("Shrubbery Creation", "home");
	std::cout << *shrub;
	supervisor.signForm(*shrub);
	supervisor.executeForm(*shrub);
	delete shrub;

	std::cout << CL << "-------------------\n" << RS;
	Form *pres = someIntern.makeForm("Presidential Pardon", "Francis");
	std::cout << *pres;
	supervisor.signForm(*pres);
	supervisor.executeForm(*pres);
	delete pres;

	std::cout << CL << "-------------------\n" << RS;
	Form *robot = someIntern.makeForm("Robotomy Request", "Bender");
	std::cout << *robot;
	francis.signForm(*robot);
	francis.executeForm(*robot);
	delete robot;


    return (0);
}
