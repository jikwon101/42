#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
class Conversion
{
private:
	enum	Type
	{
		YET = -1,
		N,
		INT,
		CHAR,
		FLOAT,
		DOUBLE,
		POSINF,
		NEGINF,
		IMPOSSIBLE
	};
	std::string raw;
	long		lval;
	double		dval;
	int			type;
	int			fraction;
	bool		isInt(std::string const & str);
	int			detectType();
	void		printMsg(std::string str) const;

public:
	Conversion(std::string src);
	~Conversion();
	Conversion(Conversion const & src);
	Conversion& operator=(Conversion const & src);
	void		printAsInt() const;
	void		printAsDouble() const;
	void		printAsFloat() const;
	void		printAsChar() const;
};

std::ostream& operator<<(std::ostream & os, Conversion const & src);

#endif
