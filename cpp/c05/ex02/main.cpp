#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

# define CL "\033[1m\033[36m"
# define RS "\033[0m"

int main()
{	
	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|               ShrubberyCreationForm 1                 |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;

	std::cout << CL << "Creating object____________\n" << RS;
	Bureaucrat *jone = new Bureaucrat("Jone", 140);
	Form *sb = new ShrubberyCreationForm("home");
	std::cout << CL << "Info of object_____________\n" << RS;
	std::cout << *jone;
	std::cout << *sb;

	std::cout << CL << "New function_______________\n" << RS;
	jone->signForm(*sb);
	jone->executeForm(*sb);

	delete jone;
	delete sb;

	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|               ShrubberyCreationForm 2                 |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;

	std::cout << CL << "Creating object____________\n" << RS;
	jone = new Bureaucrat("Jone", 120);
	sb = new ShrubberyCreationForm("home");
	
	std::cout << CL << "Info of object_____________\n" << RS;
	std::cout << *jone;
	std::cout << *sb;

	std::cout << CL << "New function_______________\n" << RS;
	jone->signForm(*sb);
	jone->executeForm(*sb);

	delete jone;
	delete sb;




	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|                RobotomyRequstForm 1                   |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "Creating object____________\n" << RS;
	jone = new Bureaucrat("Jone", 60);
	sb = new RobotomyRequestForm("Bender");
	std::cout << CL << "Info of object_____________\n" << RS;
	std::cout << *jone;
	std::cout << *sb;

	std::cout << CL << "New function_______________\n" << RS;
	jone->signForm(*sb);
	jone->executeForm(*sb);

	delete jone;
	delete sb;


	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|                RobotomyRequstForm 2                   |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;
	
	std::cout << CL << "Creating object____________\n" << RS;
	jone = new Bureaucrat("Jone", 20);
	sb = new RobotomyRequestForm("Bender");
	std::cout << CL << "Info of object_____________\n" << RS;
	std::cout << *jone;
	std::cout << *sb;

	std::cout << CL << "New function_______________\n" << RS;
	jone->signForm(*sb);
	jone->executeForm(*sb);

	delete jone;
	delete sb;

	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|               PresidentialPardonForm 1                |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;

	std::cout << CL << "Creating object____________\n" << RS;
	jone = new Bureaucrat("Jone", 15);
	sb = new PresidentialPardonForm("Francis");
	std::cout << CL << "Info of object_____________\n" << RS;
	std::cout << *jone;
	std::cout << *sb;

	std::cout << CL << "New function_______________\n" << RS;
	jone->signForm(*sb);
	jone->executeForm(*sb);

	delete jone;
	delete sb;

	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|               PresidentialPardonForm 2                |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;

	std::cout << CL << "Creating object____________\n" << RS;
	jone = new Bureaucrat("Jone", 2);
	sb = new PresidentialPardonForm("Francis");
	std::cout << CL << "Info of object_____________\n" << RS;
	std::cout << *jone;
	std::cout << *sb;

	std::cout << CL << "New function_______________\n" << RS;
	jone->signForm(*sb);
	jone->executeForm(*sb);

	delete jone;
	delete sb;


}
