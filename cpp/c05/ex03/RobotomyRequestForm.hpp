#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	RobotomyRequestForm();
	static const int	_exec_grade;
	static const int	_sign_grade;
	
public:
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	RobotomyRequestForm& operator=(RobotomyRequestForm const & src);
	void execute(Bureaucrat const & executor) const throw (NotSigned, NotHighEnoughGrade, CantOpenFile);
	
};

#endif
