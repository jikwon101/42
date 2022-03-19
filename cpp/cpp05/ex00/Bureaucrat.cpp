#include "Bureaucrat.hpp"

/*
** Exception
*/
const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("GradeTooLowException");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("GradeTooHighException");
}


/*
** Coplien's Form
*/

Bureaucrat::Bureaucrat():name(""){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name , int grade) throw (GradeTooHighException, GradeTooLowException) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
	std::cout << name << " is successfully created." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src):name(src.getName())
{	
	this->grade = src.grade;
	std::cout << this->name << " is successfully created." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & src)
{
	if (this != &src)
	{
		this->grade = src.grade;
	}
	return (*this);
}


/*
** Setter & Getter
*/

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
		std::cout << "Upgrade is failed, because of ";
		std::cout << err.what() << std::endl;
		return ;
	}
	catch (GradeTooHighException& err)
	{
		std::cout << "Upgrade is failed, because of ";
		std::cout << err.what() << std::endl;
		return ;
	}
	std::cout << name << " has successfully upgraded." << std::endl;
}

void Bureaucrat::downGrade(void)
{	
	try
	{
		setGrade(this->grade + 1);
	}
	catch (GradeTooLowException& err)
	{
		std::cout << "Downgrade is failed, because of ";
		std::cout << err.what() << std::endl;
		return ;
	}
	catch (GradeTooHighException& err)
	{
		std::cout << "Downgrade is failed, because of ";
		std::cout << err.what() << std::endl;
		return ;
	}
	std::cout << name << " has successfully downgraded." << std::endl;
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
