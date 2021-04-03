#include "Conversion.hpp"

Conversion::Conversion(std::string raw)
{
	this->raw = raw;
	this->fraction = 1;
	this->sign = 1;
	type = detectType();
	fraction = 1;
	if (type == CHAR)
	{
		ival = static_cast<int64_t>(raw.c_str()[0]);
		dval = static_cast<double>(ival);
	}
	else
	{
		dval = toDval();
		ival = static_cast<int64_t>(dval);
	}
}

double	Conversion::toDval()
{
	size_t		pos_dot;
	double		res = 0;

	if (type != FLOAT && type != DOUBLE && type != CHAR && type != INT)
		return (0);
	res = atof(raw.c_str());
	pos_dot = raw.find(".");
	if (pos_dot != std::string::npos)
		this->fraction = 2;
	if (raw.find("-") != std::string::npos)
		this->sign = -1;
	return (res);
}


void	Conversion::printAsChar(std::ostream & os) const
{
	os << "char: ";
	if (type == N || type == IMPOSSIBLE || type == POSINF || type == NEGINF)
	{
		os << "impossible\n";
		return ;
	}
	if ((ival ^ sign) < 0)
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
	else if (((int64_t)dval ^ sign) < 0)
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
	else if (((int64_t)dval ^ (int64_t)sign) < 0)
	{
		os << "impossible\n";
	}
	else
	{
		os.precision(fraction);
		os << std::fixed << static_cast<float>(dval);
		os << "f" << std::endl;
	}
}

