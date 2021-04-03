#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>
#include <string>

class Conversion
{
private:
	enum	Type
	{
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
	int64_t		ival;
	double		dval;
	int			type;
	int			fraction;
	int			sign;
	bool		isDecimalNbr(std::string const & src, size_t pos_dot, size_t pos_eplus);
	bool		isInt(std::string const & str);
	int			detectType();

public:
	Conversion(std::string src);
	~Conversion();
	Conversion(Conversion const & src);
	Conversion& operator=(Conversion const & src);
	void		printAsInt(std::ostream & os) const;
	void		printAsDouble(std::ostream & os) const;
	void		printAsFloat(std::ostream & os) const;
	void		printAsChar(std::ostream & os) const;
};

std::ostream& operator<<(std::ostream & os, Conversion const & src);

#endif
