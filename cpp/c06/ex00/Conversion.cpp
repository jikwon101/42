#include "Conversion.hpp"

Conversion::Conversion(std::string raw)
{
	this->raw = raw;
	this->fraction = 1;
	this->sign = 1;
	type = detectType();
	fraction = 1;
	std::cout << CL << printtype() << std::endl << RS;
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
	/*
	if (type == CHAR || type == INT)
		dval = static_cast<double>(ival);
	else if (type == DOUBLE || type == FLOAT)
		ival = static_cast<int>(dval);
*/
}

double	Conversion::toDval()
{
	//int			i = 0;
	//int			count = 1;
	double		res = 0;
	//const char	*val;

	//if (type != FLOAT && type != DOUBLE)
	//	return (0);
	if (type != FLOAT && type != DOUBLE && type != CHAR && type != INT)
		return (0);
	res = atof(raw.c_str());
	size_t pos_dot;
	pos_dot = raw.find(".");
	if (pos_dot != std::string::npos)
		this->fraction = 2;
	if (raw.find("-") != std::string::npos)
		this->sign = -1;
	return (res);
	/*
	val = raw.c_str();
	if (val[0] == '-')
	{
		i++;
		this->sign = -1;
	}
	while (val[i] && val[i] != '.' && val[i] != 'f')
	{
		res = res * 10 + (val[i] - '0');
		i++;
	}
	if (val[i] == '.')
		i++;
	while (val[i] && val[i] != 'f')
	{
		res = res + (val[i] - '0') / (pow(10, count));
		count++;
		i++;
	}
	this->fraction = (5 < count - 1) ? 5 : count - 1;
	if (this->sign < 0)
		return (-res);
	return (res);*/
}


void	Conversion::printAsChar() const
{
	if (type == N || type == IMPOSSIBLE || type == POSINF || type == NEGINF)
	{
		std::cout << "impossible";
		return ;
	}
	if ((ival ^ sign) < 0)
		std::cout << "impossible";
	else if (ival > 127)
		std::cout << "impossible";
	else if (ival < 32)
		std::cout << "Not displayable";
	else
		std::cout << "'" << static_cast<char>(ival) << "'";
}

void	Conversion::printAsInt() const
{
	if (type == N || type == IMPOSSIBLE || type == POSINF || type == NEGINF)
		std::cout << "impossible";
	else if (ival < INT_MIN || ival > INT_MAX)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(ival);
	/*
	else if (type == INT || type == CHAR)
	{
		if ((ival ^ sign) < 0)
		{
			std::cout << "impossible";
			return ;
		}
		std::cout << static_cast<int>(ival);
	}
	else
	{
		if (((int)dval ^ sign) < 0)
		{
			std::cout << "impossible";
			return ;
		}
		std::cout << static_cast<int>(dval);
	}
	*/
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
	else if (((int64_t)dval ^ sign) < 0)
		std::cout << "impossible";
	else
	{
		std::cout.precision(fraction);
		std::cout << std::fixed << dval;
	}

	/*
	else if (type == INT || type == CHAR)
	{	
		if (((int64_t)ival ^ sign) < 0)
		{
			std::cout << "impossible";
			return ;
		}
		std::cout.precision(fraction);
		std::cout << std::fixed << static_cast<double>(ival);
	}
	else
	{
		if (((int64_t)dval ^ sign) < 0)
		{
			std::cout << "impossible";
			return ;
		}
		std::cout << static_cast<double>(dval);
	}
	*/
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
	else if (((int64_t)dval ^ (int64_t)sign) < 0)
	{
		std::cout << "impossible";
	}
	else
	{
		std::cout.precision(fraction);
		std::cout << std::fixed << static_cast<float>(dval);
		std::cout << "f";
	}

	/*
	else if (type == INT || type == CHAR)
	{
		if (((int64_t)ival ^ (int64_t)sign) < 0)
		{
			std::cout << "!!!! " << (int64_t)ival;
			std::cout << "impossible";
			return ;
		}
		std::cout.precision(fraction);
		std::cout << std::fixed << static_cast<float>(ival);
		std::cout << "f";
	}
	else
	{
		if (((int64_t)dval ^ sign) < 0)
		{
			std::cout << "impossible";
			return ;
		}
		std::cout.precision(fraction);
		std::cout << std::fixed << static_cast<float>(dval);
		std::cout << "f";
	}
*/

}

