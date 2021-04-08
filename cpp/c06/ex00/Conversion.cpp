#include "Conversion.hpp"

/*
** Coplien's Form
*/
Conversion::Conversion(std::string raw)
{
	this->raw = raw;
	this->fraction = 1;
	this->sign = (raw.find("-") == std::string::npos) ? 1 : -1;
	type = detectType();
	if (type == CHAR)
	{
		ival = static_cast<int64_t>(raw.c_str()[0]);
		dval = static_cast<double>(ival);
	}
	else
	{
		dval = atof(raw.c_str());
		ival = static_cast<int64_t>(dval);
	}
}

Conversion::~Conversion(){}

Conversion::Conversion(Conversion const & src)
{
	raw = src.raw;
	ival = src.ival;
	dval = src.dval;
	type = src.type;
	fraction = src.fraction;
	sign = src.sign;
}

Conversion& Conversion::operator=(Conversion const & src)
{
	if (this != &src)
	{
		raw = src.raw;
		ival = src.ival;
		dval = src.dval;
		type = src.type;
		fraction = src.fraction;
		sign = src.sign;
	}
	return (*this);
}

/*
** Print Function : Public
*/
void	Conversion::printAsChar(std::ostream & os) const
{
	os << "char: ";
	if (type == N || type == IMPOSSIBLE || type == POSINF || type == NEGINF)
		os << "impossible\n";
	else if ((ival ^ sign) < 0)
		os << "impossible\n";
	else if (ival > 127)
		os << "impossible\n";
	else if (ival < 32)
		os << "Not displayable\n";
	else
		os << "'" << static_cast<char>(ival) << "'" << std::endl;
}

void	Conversion::printAsInt(std::ostream & os) const
{
	os << "int: ";
	if (type == N || type == IMPOSSIBLE || type == POSINF || type == NEGINF)
		os << "impossible\n";
	else if (ival < INT_MIN || ival > INT_MAX)
		os << "impossible\n";
	else
		os << static_cast<int>(ival) << std::endl;
}

void	Conversion::printAsDouble(std::ostream & os) const
{
	os << "double: ";
	if (type == IMPOSSIBLE)
		os << "impossible\n";
	else if (type == POSINF)
		os << "inf\n";
	else if (type == NEGINF)
		os << "-inf\n";
	else if (type == N)
		os << "nan\n";
	else if ((static_cast<int64_t>(dval) ^ sign) < 0)
		os << "impossible\n";
	else
	{
		os.precision(fraction);
		os << std::fixed << dval << std::endl;;
	}
}

void	Conversion::printAsFloat(std::ostream & os) const
{
	os << "float: ";
	if (type == IMPOSSIBLE)
		os << "impossible\n";
	else if (type == POSINF)
		os << "inff\n";
	else if (type == NEGINF)
		os << "-inff\n";
	else if (type == N)
		os << "nanf\n";
	else if ((static_cast<int64_t>(dval) ^ sign) < 0)
		os << "impossible\n";
	else
	{
		os.precision(fraction);
		os << std::fixed << static_cast<float>(dval);
		os << "f" << std::endl;
	}
}

/*
** Overload ostream operator
*/
std::ostream& operator<<(std::ostream & os, Conversion const & src)
{
	src.printAsChar(os);
	src.printAsInt(os);
	src.printAsFloat(os);
	src.printAsDouble(os);
	return (os);
}


/*
** Member Function : private
*/
int	Conversion::detectType()
{
	std::string	src;
	size_t 		pos_dot;
	size_t		pos_minus;
	size_t		pos_eplus;

	pos_minus = raw.find("-");
	src = (pos_minus == std::string::npos) ? raw : raw.substr(1, raw.length() - 1);
	pos_dot = src.find(".");
	pos_eplus = src.find("e+");

	if (pos_dot != std::string::npos || pos_eplus != std::string::npos)
	{
		if (isDecimalNbr(src, pos_dot, pos_eplus) == false)
			return (IMPOSSIBLE);
		else if (src.find("f") != std::string::npos)
			return (FLOAT);
		return (DOUBLE);
	}
	if (raw == "nan" || raw == "nanf")
		return (N);
	if (raw == "inf" || raw == "inff")
		return (POSINF);
	if (raw == "-inf" || raw == "-inff")
		return (NEGINF);
	if (raw.length() == 1 && (isInt(raw) == false))
		return (CHAR);
	if (isInt(src) == true)
		return (INT);
	return (IMPOSSIBLE);
}

bool	Conversion::isInt(std::string const & str)
{
	const char	*val;
	int 		i;

	i = 0;
	val = str.c_str();
	while (val[i])
	{
		if ('0' <= val[i] && val[i] <= '9')
			i++;
		else
			return (false);
	}
	return (true);
}

bool Conversion::isDecimalNbr(std::string const & src, size_t pos_dot, size_t pos_eplus)
{
	size_t length;

	if (src.find("f") == src.length() - 1)
		length = src.length() - 1;
	else
		length = src.length();
	if (pos_eplus == std::string::npos)
	{
		if (isInt(src.substr(0, pos_dot)) == false)
			return (false);
		if (pos_dot == length - 1)
			return (true);
		if (isInt(src.substr(pos_dot + 1, length - 1 - pos_dot)) == false)
			return (false);
	}
	else if (pos_dot == std::string::npos)
	{
		if (isInt(src.substr(0, pos_eplus)) == false)
			return (false);
		if (isInt(src.substr(pos_eplus + 2, length - pos_eplus -2)) == false)
			return (false);
	}
	else
	{
		if (pos_eplus < pos_dot)
			return (false);
		if (isInt(src.substr(0, pos_dot)) == false)
			return (false);
		if (isInt(src.substr(pos_dot + 1, pos_eplus - 1 - pos_dot - 1 + 1)) == false)
			return (false);
		if (isInt(src.substr(pos_eplus + 2, length - pos_eplus - 2)) == false)
			return (false);
	}
	return (true);
}

