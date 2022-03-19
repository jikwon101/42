#include "PresidentialPardonForm.hpp"

/*
** Static variable
*/
const int PresidentialPardonForm::_sign_grade = 25;
const int PresidentialPardonForm::_exec_grade = 5;

/*
** Coplien's Form
*/
PresidentialPardonForm::PresidentialPardonForm()
		:Form("PresidentialPardonForm", "", PresidentialPardonForm::_sign_grade, PresidentialPardonForm::_exec_grade) {}
	
PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
		:Form("PresidentialPardonForm", target, PresidentialPardonForm::_sign_grade, PresidentialPardonForm::_exec_grade)
{
	std::cout << this->getName() << " is successfully created ";
	std::cout << "with target : " << this->getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
		:Form("PresidentialPardonForm", src.getTarget(), PresidentialPardonForm::_sign_grade, PresidentialPardonForm::_exec_grade)
{
	std::cout << this->getName() << " is successfully created ";
	std::cout << "with target : " << this->getTarget() << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	this->setTarget(src.getTarget());
	return (*this);
}

/*
** Member Function
*/
void PresidentialPardonForm::execute(Bureaucrat const & executor) const throw (Form::NotSigned, Form::NotHighEnoughGrade, Form::CantOpenFile)
{
	if (this->getIsSigned() == false)
		throw (Form::NotSigned());
	if (executor.getGrade() > this->getExecuteGrade())
		throw (Form::NotHighEnoughGrade());
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
