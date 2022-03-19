#include "ShrubberyCreationForm.hpp"

/*
** Static variable
*/
const int ShrubberyCreationForm::_sign_grade = 145;
const int ShrubberyCreationForm::_exec_grade = 137;

/*
** Coplien's Form
*/
ShrubberyCreationForm::ShrubberyCreationForm()
		:Form("ShrubberyCreationForm", "", ShrubberyCreationForm::_sign_grade, ShrubberyCreationForm::_exec_grade) {}
	
ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
		:Form("ShrubberyCreationForm", target, ShrubberyCreationForm::_sign_grade, ShrubberyCreationForm::_exec_grade)
{
	std::cout << this->getName() << " is successfully created ";
	std::cout << "with target : " << this->getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
		:Form("ShrubberyCreationForm", src.getTarget(), ShrubberyCreationForm::_sign_grade, ShrubberyCreationForm::_exec_grade)
{
	std::cout << this->getName() << " is successfully created ";
	std::cout << "with target : " << this->getTarget() << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	this->setTarget(src.getTarget());
	return (*this);
}

/*
** Member Function
*/
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const throw (Form::NotSigned, Form::NotHighEnoughGrade, Form::CantOpenFile)
{
	std::string filename;
	std::ofstream outfile;
	std::string buffer;

	if (this->getIsSigned() == false)
		throw (Form::NotSigned());
	if (executor.getGrade() > this->getExecuteGrade())
		throw (Form::NotHighEnoughGrade());
	filename = this->getTarget();
	filename += "_shrubbery";
	outfile.open(filename);
	if (outfile.fail())
		throw (Form::CantOpenFile());
	buffer = drawTree();
	outfile.write(buffer.c_str(), buffer.length());
	outfile.close();
	std::cout << "File : " << filename << " is created." << std::endl;
}

std::string ShrubberyCreationForm::drawTree(void) const
{
	return ("          .     .  .      +     .      .          .\n     .       .      .     #       .           .\n        .      .         ###            .      .      .\n      .      .   \"#:. .:##\"##:. .:#\"  .      .\n          .      . \"####\"###\"####\"  .\n       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n  .             \"#########\"#########\"        .        .\n        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n                .\"##\"#####\"#####\"##\"           .      .\n    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n      .     \"#######\"##\"#####\"##\"#######\"      .     .\n    .    .     \"#####\"\"#######\"\"#####\"    .      .\n            .     \"      000      \"    .     .\n       .         .   .   000     .        .       .\n.. .. ..................O000O........................ ......\n");
}
