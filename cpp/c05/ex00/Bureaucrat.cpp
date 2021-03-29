#include "Bureaucrat.hpp"

/*
** Exception
*/
const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("GradeTooLowException\n");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("GraedTooHighException\n");
}


/*
** Coplien's Form
*/

Bureaucrat::Bureaucrat(){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name , int grade)
{
	setName(name);
	try
	{
		setGrade(grade);
	}
	catch (GradeTooLowException& err)
	{
		std::cout << err.what();
	}
	catch (GradeTooHighException& err)
	{
		std::cout << err.what();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat &src)
{	
	setName(src.getName());
	try
	{
		setGrade(src.getGrade());
	}
	catch (GradeTooLowException& err)
	{
		std::cout << err.what();
	}
	catch (GradeTooHighException& err)
	{
		std::cout << err.what();
	}
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &src)
{
	if (this != &src)
	{
		setName(src.getName());
		try
		{
			setGrade(src.getGrade());
		}
		catch (GradeTooLowException& err)
		{
			std::cout << err.what();
		}
		catch (GradeTooHighException& err)
		{
			std::cout << err.what();
		}
	}
	return (*this);
}


/*
** Setter & Getter
*/
void Bureaucrat::setName(std::string const name)
{
	this->name = name;
}

void Bureaucrat::setGrade(int const grade) throw(GradeTooHighException, GradeTooLowException)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}


/*
** Member Function
*/
void Bureaucrat::upGrade(void)
{
	try
	{
		setGrade(this->grade - 1);
	}
	catch (GradeTooLowException& err)
	{
		std::cout << err.what();
	}
	catch (GradeTooHighException& err)
	{
		std::cout << err.what();
	}
}

void Bureaucrat::downGrade(void)
{	
	try
	{
		setGrade(this->grade + 1);
	}
	catch (GradeTooLowException& err)
	{
		std::cout << err.what();
	}
	catch (GradeTooHighException& err)
	{
		std::cout << err.what();
	}
}


/*
** Overload ostream operator 
*/
std::ostream& operator<<(std::ostream& os, Bureaucrat const & src)
{
	os << src.getName();
	os << ", bureaucrat grade ";
	os << src.getGrade();
	os << "\n";
	return (os);
}
