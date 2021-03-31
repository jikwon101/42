#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>
#include <string>

# define CL "\033[1m\033[36m"
# define RS "\033[0m"

class Conversion
{
private:
	std::string raw;
	int		ival;
	double	dval;
	int		type;
public:
	enum	literal
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
	void		printAsInt() const;
	void		printAsDouble() const;
	void		printAsFloat() const;
	void		printAsChar() const;
	int			getType() const;
	int			detectType();
	std::string printtype();
	int			toIval();
	double		toDval();
};

std::ostream& operator<<(std::ostream & os, Conversion const & src);

#endif
