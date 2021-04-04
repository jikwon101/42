#include "Conversion.hpp"

/* not in class */
bool	Conversion::isInt(std::string const & str)
{
	const char *val;
	val = str.c_str();
	int i = 0;

	while (val[i])
	{
		if ('0' <= val[i] && val[i] <= '9')
			i++;
		else
			return (false);
	}
	return (true);
}


std::ostream& operator<<(std::ostream & os, Conversion const & src)
{
	src.printAsChar(os);
	src.printAsInt(os);
	src.printAsFloat(os);
	src.printAsDouble(os);
	return (os);
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

int	Conversion::detectType()
{
	std::string	src;
	size_t 		pos_dot;
	size_t		pos_minus;
	size_t		pos_f;
	size_t		pos_eplus;

	pos_minus = raw.find("-");
	src = (pos_minus == std::string::npos) ? raw : raw.substr(1, raw.length() - 1);
	pos_dot = src.find(".");
	pos_f = src.find("f");
	pos_eplus = src.find("e+");

	if (pos_dot != std::string::npos || pos_eplus != std::string::npos)
	{
		if (isDecimalNbr(src, pos_dot, pos_eplus) == false)
			return (IMPOSSIBLE);
		else if (pos_f != std::string::npos)
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


int		Conversion::getType() const
{
	return (type);
}

