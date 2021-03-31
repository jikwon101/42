#include "RobotomyRequestForm.hpp"

/*
** Static variable
*/
const int RobotomyRequestForm::_sign_grade = 72;
const int RobotomyRequestForm::_exec_grade = 45;

/*
** Coplien's Form
*/
RobotomyRequestForm::RobotomyRequestForm()
		:Form("RobotomyRequestForm", "", RobotomyRequestForm::_sign_grade, RobotomyRequestForm::_exec_grade) {}
	
RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
		:Form("RobotomyRequestForm", target, RobotomyRequestForm::_sign_grade, RobotomyRequestForm::_exec_grade)
{
	std::cout << this->getName() << " is successfully created ";
	std::cout << "with target : " << this->getTarget() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
		:Form("RobotomyRequestForm", src.getTarget(), RobotomyRequestForm::_sign_grade, RobotomyRequestForm::_exec_grade)
{
	std::cout << this->getName() << " is successfully created ";
	std::cout << "with target : " << this->getTarget() << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	this->setTarget(src.getTarget());
	return (*this);
}

/*
** Member Function
*/
void RobotomyRequestForm::execute(Bureaucrat const & executor) const throw (Form::NotSigned, Form::NotHighEnoughGrade, Form::CantOpenFile)
{
	if (this->getIsSigned() == false)
		throw (Form::NotSigned());
	if (executor.getGrade() > this->getExecuteGrade())
		throw (Form::NotHighEnoughGrade());
	std::cout << "whirrrrrr!!!!" << std::endl;
	std::cout << this->getTarget() << " has been Robotomized successfully 50\% of the time" << std::endl;
}
