#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	PresidentialPardonForm();
	static const int	_exec_grade;
	static const int	_sign_grade;
	
public:
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	PresidentialPardonForm& operator=(PresidentialPardonForm const & src);
	void execute(Bureaucrat const & executor) const throw (NotSigned, NotHighEnoughGrade, CantOpenFile);
	
};

#endif
