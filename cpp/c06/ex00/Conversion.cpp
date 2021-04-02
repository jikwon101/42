#include "Conversion.hpp"

std::ostream& operator<<(std::ostream & os, Conversion const & src)
{
	
	os << "char: ";
	src.printAsChar();
	os << "\nint: ";
	src.printAsInt();
	os << "\nfloat: ";
	src.printAsFloat();
	os << "\ndouble: ";
	src.printAsDouble();
	os << std::endl;
	return (os);
}

/* temp */
std::string Conversion::printtype()
{
	switch(type)
	{
		case N:
			return "N";
			break;
		case INT:
			return "INT";
			break;
		case CHAR:
			return "CHAR";
			break;
		case FLOAT:
			return "FLOAT";
			break;
		case DOUBLE:
			return "DOUBLE";
			break;
		case POSINF:
			return "POSINF";
			break;
		case NEGINF:
			return "NEGINF";
			break;
		case IMPOSSIBLE:
			return "IMPOSSIBLE";
			break;
		default:
			return "";
			break;
	}
}

int		Conversion::toIval()
{
	int			i = 0;
	int			res = 0;
	bool		minus = false;
	const char	*val;

	if (type != INT && type != CHAR)
		return (0);
	val = raw.c_str();
	if (type == CHAR)
		return (val[0]);
	if (val[0] == '-')
	{
		i++;
		minus = true;
	}
	while (val[i])
	{
		res = res * 10 + (val[i] - '0');
		i++;
	}
	if (minus == true)
		return (-res);
	return (res);
}

double	Conversion::toDval()
{
	int			i = 0;
	int			count = 1;
	bool		minus = false;
	double		res = 0;
	const char	*val;

	if (type != FLOAT && type != DOUBLE)
		return (0);
	val = raw.c_str();
	if (val[0] == '-')
	{
		i++;
		minus = true;
	}
	while (val[i] && val[i] != '.')
	{
		res = res * 10 + (val[i] - '0');
		i++;
	}
	if (val[i] == '.')
		i++;
	while (val[i])
	{
		res = res + (val[i] - '0') / (pow(10, count));
		count++;
		i++;
	}
	if (minus == true)
		return (-res);
	return (res);
}

Conversion::Conversion(std::string raw)
{
	this->raw = raw;
	type = detectType();
	std::cout << CL << printtype() << std::endl << RS;
	ival = toIval();
	dval = toDval();
}

/* not in class*/
bool isNum(std::string str)
{
	const char *val;

	val = str.c_str();
	if ('0' <= *val && *val <= '9')
		return (true);
	return (false);
}

/* not in class */
bool	isInt(std::string str)
{
	const char *val;
	val = str.c_str();
	int i = 0;

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

int	Conversion::detectType()
{
	size_t pos_dot;
	size_t pos_minus;
	size_t pos_f;

	pos_dot = raw.find(".");
	pos_minus = raw.find("-");
	pos_f = raw.find("f");

	if (pos_dot != std::string::npos)
	{
		if (pos_f != std::string::npos)
			return (FLOAT);
		return (DOUBLE);
	}
	if (raw == "nan" || raw == "nanf")
		return (N);
	if (raw == "inf" || raw == "inff")
		return (POSINF);
	if (raw == "-inf" || raw == "-inff")
		return (NEGINF);
	if (raw.length() == 1 && (isNum(raw) == false))
		return (CHAR);
	if (isInt(raw) == true)
		return (INT);
	return (IMPOSSIBLE);
}

void	Conversion::printAsInt() const
{
	if (type == N || type == IMPOSSIBLE || type == POSINF || type == NEGINF)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(ival) ;
}

void	Conversion::printAsDouble() const
{
	if (type == IMPOSSIBLE)
		std::cout << "impossible";
	else if (type == POSINF)
		std::cout << "inf";
	else if (type == NEGINF)
		std::cout << "-inf";
	else if (type == N)
		std::cout << "nan";
	else if (type == INT || type == CHAR)
	{
		std::cout.precision(1);
		std::cout << std::fixed << static_cast<double>(ival);
	}
	else
		std::cout << static_cast<double>(dval);
}

void	Conversion::printAsFloat() const
{
	if (type == IMPOSSIBLE)
		std::cout << "impossible";
	else if (type == POSINF)
		std::cout << "inff";
	else if (type == NEGINF)
		std::cout << "-inff";
	else if (type == N)
		std::cout << "nanf";
	else if (type == INT || type == CHAR)
	{
		std::cout.precision(1);
		std::cout << std::fixed << static_cast<float>(ival);
		std::cout << "f";
	}
	else
	{
		std::cout << static_cast<float>(dval);
		std::cout << "f";
	}


}
void	Conversion::printAsChar() const
{
	if (type == N || type == IMPOSSIBLE || type == POSINF || type == NEGINF)
	{
		std::cout << "impossible";
		return ;
	}
	if (ival > 127)
		std::cout << "impossible";
	else if (ival < 32)
		std::cout << "Not displayable";
	else
		std::cout << "'" << static_cast<char>(ival) << "'";
}

int		Conversion::getType() const
{
	return (type);
}
