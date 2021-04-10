#ifndef EXTRA_HPP
# define EXTRA_HPP

#include <iostream>

class My
{
private:
	int nbr;
public:
	My(int nbr = 0);
	My(My const & src);
	My& operator=(My const & src);
	~My();
	int	getNbr(void) const;
	bool operator>(My const & other) const;
	bool operator<(My const & other) const;
	bool operator==(My const & other) const;
	bool operator!=(My const & other) const;
	bool operator>=(My const & other) const;
	bool operator<=(My const & other) const;
};

std::ostream& operator << (std::ostream &os, My const & src);

#endif
