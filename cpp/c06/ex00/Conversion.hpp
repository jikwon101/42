#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
# define CL "\033[1m\033[36m"
# define RS "\033[0m"

class Conversion
{
private:
	std::string raw;
	int64_t		ival;
	double		dval;
	int			type;
	int			fraction;
	int			sign;
public:
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
	Conversion(std::string src);
//	~Conversion();
//	Conversion(Conversion & const src);
//	Conversion& operator=(Conversion & const src);
	void		printAsInt(std::ostream & os) const;
	void		printAsDouble(std::ostream & os) const;
	void		printAsFloat(std::ostream & os) const;
	void		printAsChar(std::ostream & os) const;
	int			getType() const;
	int			detectType();
	//std::string printtype();
	//int			toIval();
	double		toDval();
};

std::ostream& operator<<(std::ostream & os, Conversion const & src);

#endif
