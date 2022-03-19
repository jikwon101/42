#include "Bureaucrat.hpp"

# define CL "\033[1m\033[36m"
# define RS "\033[0m"

int main()
{	
	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|                    Create object                      |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;

	Bureaucrat jone("Jone", 4);
	Bureaucrat cathy("cathy", 149);

	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|                Create Bureaucrat error                |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;

	try
	{
		std::cout << CL << "Trying to create (name, 0)\n" << RS;
		Bureaucrat err1("high", 0);
	}
	catch (Bureaucrat::GradeTooHighException & err)
	{
		std::cout << "Cannot create because of ";
		std::cout << err.what() << std::endl;
	}
	try
	{
		std::cout << CL << "Trying to create (name, 166)\n" << RS;
		Bureaucrat err2("low", 166);
	}
	catch (Bureaucrat::GradeTooLowException & err)
	{
		std::cout << "Cannot create because of ";
		std::cout << err.what() << std::endl;
	}

	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|                    Info object                        |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;

	std::cout << jone;
	std::cout << cathy;

	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|             Downgrade Bureaucrat object               |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;
	
	cathy.downGrade();
	std::cout << cathy;
	cathy.downGrade();

	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|             Upgrade Bureaucrat object                 |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;
	
	jone.upGrade();
	jone.upGrade();
	std::cout << jone;
	jone.upGrade();
	std::cout << jone;
	jone.upGrade();
	jone.upGrade();
	jone.upGrade();
	

}
