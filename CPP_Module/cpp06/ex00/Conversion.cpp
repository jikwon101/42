#include "Conversion.hpp"

/*
** Coplien's Form
*/
Conversion::Conversion(std::string raw)
{
	char *err = 0;
	this->raw = raw;
	this->fraction = 1;
	type = detectType();
	if (type == CHAR)
	{
		lval = static_cast<int>(raw.c_str()[0]);
		dval = static_cast<double>(raw.c_str()[0]);
	}
	else if (type == INT || type == YET)
	{
		const char *c_raw = raw.c_str();
		double temp = strtod(c_raw, &err);
		
		if (err[0] == 'f' && err[1] == '\0')
			type = FLOAT;
		else if (type != FLOAT && *err != '\0')
			type = IMPOSSIBLE;
		if (type != IMPOSSIBLE)
		{
			dval = temp;
			lval = static_cast<int>(dval);
			if (type == YET)
				type = DOUBLE;
		}
	}
}

Conversion::~Conversion(){}

Conversion::Conversion(Conversion const & src)
{
	raw = src.raw;
	lval = src.lval;
	dval = src.dval;
	type = src.type;
	fraction = src.fraction;
}

Conversion& Conversion::operator=(Conversion const & src)
{
	if (this != &src)
	{
		raw = src.raw;
		lval = src.lval;
		dval = src.dval;
		type = src.type;
		fraction = src.fraction;
	}
	return (*this);
}

/*
** Print Function : Public
*/
void	Conversion::printAsChar() const
{
	std::cout << "char: ";
	if (type == N || type == IMPOSSIBLE || type == POSINF || type == NEGINF)
		return (printMsg("impossible\n"));
	else if (type != CHAR)
	{
		if (dval > INT_MAX || dval < INT_MIN)
			return (printMsg("impossible\n"));
	}
	if (dval > 127 || dval < 0)
		return (printMsg("impossible\n"));
	else if (dval < 32)
		return (printMsg("Non displayable\n"));
	std::cout << "'" << static_cast<char>(lval) << "'" << std::endl;
}

void	Conversion::printAsInt() const
{
	std::cout << "int: ";
	if (type == N || type == IMPOSSIBLE || type == POSINF || type == NEGINF)
		return (printMsg("impossible\n"));
	else if (type != CHAR)
	{
		if (dval > INT_MAX || dval < INT_MIN)
			return (printMsg("impossible\n"));
	}
	std::cout << static_cast<int>(lval) << std::endl;
}

void	Conversion::printAsDouble() const
{
	std::cout << "double: ";
	if (type == IMPOSSIBLE)
		return (printMsg("impossible\n"));
	else if (type == POSINF)
		return (printMsg("inf\n"));
	else if (type == NEGINF)
		return (printMsg("-inf\n"));
	else if (type == N)
		return (printMsg("nan\n"));
	std::cout.precision(fraction);
	std::cout << std::fixed << dval << std::endl;;
}

void	Conversion::printAsFloat() const
{
	std::cout << "float: ";
	if (type == IMPOSSIBLE)
		return (printMsg("impossible\n"));
	else if (type == POSINF)
		return (printMsg("inff\n"));
	else if (type == NEGINF)
		return (printMsg("-inff\n"));
	else if (type == N)
		return (printMsg("nanf\n"));
	else
	{
		std::cout.precision(fraction);
		std::cout << std::fixed << static_cast<float>(dval);
		std::cout << "f" << std::endl;
	}
}

void Conversion::printMsg(std::string str) const
{
	std::cout << str;
}

/*
** Overload ostream operator
*/
std::ostream& operator<<(std::ostream & os, Conversion const & src)
{
	src.printAsChar();
	src.printAsInt();
	src.printAsFloat();
	src.printAsDouble();
	return (os);
}

/*
** Member Function : private
*/

int	Conversion::detectType()
{
	std::string	src;

	if (raw == "nan" || raw == "nanf")
		return (N);
	if (raw == "inf" || raw == "inff")
		return (POSINF);
	if (raw == "-inf" || raw == "-inff")
		return (NEGINF);
	if (raw.length() == 1 && (isInt(raw) == false))
		return (CHAR);
	if (isInt(raw) == true)
		return (INT);
	return (YET);
}

bool	Conversion::isInt(std::string const & str)
{
	const char	*val;
	int 		i;

	i = 0;
	val = str.c_str();
	if (val[1] == '\0' && val[0] == '-')
		return (false);
	if (val[i] == '-')
		i++;
	while (val[i])
	{
		if ('0' <= val[i] && val[i] <= '9')
			i++;
		else
			return (false);
	}
	return (true);
}
