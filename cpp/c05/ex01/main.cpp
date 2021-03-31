#include "Bureaucrat.hpp"
#include "Form.hpp"

# define CL "\033[1m\033[36m"
# define RS "\033[0m"

int main()
{	
	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|                    Create object                      |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;

	Bureaucrat jone("Jone", 6);
	Form form("Commitment", 4, 3);
	Form test(form);

	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|                Create form error                      |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;

	try
	{
		std::cout << CL << "Trying to create form(name, 0, 4)\n" << RS;
		Form err1 = Form("ErrForm", 0, 4);
	}
	catch (Form::GradeTooHighException & err)
	{
		std::cout << "Cannot create because of ";
		std::cout << err.what() << std::endl;
	}
	try
	{
		std::cout << CL << "Trying to create form(name, 4, 166)\n" << RS;
		Form err2 = Form("ErrForm", 4, 166);
	}
	catch (Form::GradeTooLowException & err)
	{
		std::cout << "Cannot create because of ";
		std::cout << err.what() << std::endl;
	}

	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|                    Info object                        |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;

	std::cout << jone;
	std::cout << form;


	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|       signForm & Form::GradeTooLowException           |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;

	jone.signForm(form);

	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|             Upgrade Bureaucrat object                 |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;
	
	jone.upGrade();
	jone.upGrade();

	std::cout << CL << "---------------------------------------------------------\n" << RS;
	std::cout << CL << "|                   signForm & beSigned                 |\n" << RS;
	std::cout << CL << "---------------------------------------------------------\n" << RS;

	std::cout << jone;
	jone.signForm(form);
	std::cout << form;
}
