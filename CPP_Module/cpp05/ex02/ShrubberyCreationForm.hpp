#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
private:
	ShrubberyCreationForm();
	static const int	_exec_grade;
	static const int	_sign_grade;
	std::string			drawTree(void) const;
	
public:
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const & src);
	void execute(Bureaucrat const & executor) const throw (NotSigned, NotHighEnoughGrade, CantOpenFile);
	
};

#endif
