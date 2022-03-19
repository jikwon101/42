#include "Form.hpp"

/*
** Exception
*/
const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("GradeTooLowException");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("GraedTooHighException");
}

const char *Form::NotSigned::what(void) const throw()
{
	return ("NotSigned");
}

const char *Form::NotHighEnoughGrade::what(void) const throw()
{
	return ("NotHighEnoughGrade");
}

const char *Form::CantOpenFile::what(void) const throw()
{
	return ("CantOpenFile");
}

/*
** Coplien's Form
*/

Form::Form()
		:name(""), sign_grade(150), execute_grade(150), is_signed(false), target("") {}

Form::~Form(){}

Form::Form(std::string name , std::string target, int sign_grade, int execute_grade)
		throw (GradeTooHighException, GradeTooLowException)
		:name(name), sign_grade(sign_grade), execute_grade(execute_grade)
{
	if (sign_grade < 1 || execute_grade < 1)
		throw GradeTooHighException();
	else if (sign_grade > 150 || execute_grade > 150)
		throw GradeTooLowException();
	this->is_signed = false;
	this->target = target;
}

Form::Form(Form const &src)
		:name(src.name),sign_grade(src.sign_grade),execute_grade(src.execute_grade)
{		
	this->is_signed = src.is_signed;
	this->target = src.target;
}

Form& Form::operator=(Form const & src)
{
	if (this != &src)
	{
		this->is_signed = src.is_signed;
		this->target = src.target;
	}
	return (*this);
}


/*
** Setter & Getter
*/
void		Form::setTarget(std::string target)
{
	this->target = target;
}

std::string	Form::getName(void) const
{
	return (this->name);
}

std::string	Form::getTarget(void) const
{
	return (this->target);
}

int			Form::getSignGrade(void) const
{
	return (this->sign_grade);
}

int			Form::getExecuteGrade(void) const
{
	return (this->execute_grade);
}

bool		Form::getIsSigned(void) const
{
	return (this->is_signed);
}

/*
** Member Function
*/
void	Form::beSigned(Bureaucrat const & src) throw (GradeTooLowException)
{
	if (src.getGrade() <= this->sign_grade)
		this->is_signed = true;
	else
		throw GradeTooLowException();
}
	
/*
** Overload ostream operator 
*/
std::ostream& operator<<(std::ostream& os, Form const & src)
{
	os << src.getName() << " is " ;
	if (src.getIsSigned() == false)
		os << "not signed, ";
	else
		os << "signed, ";
	os << "it is signable at grade : " << src.getSignGrade();
	os << " and executable at grade : " << src.getExecuteGrade();
	os << "." << std::endl;
	return (os);
}
