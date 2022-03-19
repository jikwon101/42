#ifndef EXTRA_HPP
# define EXTRA_HPP

#include <iostream>

class My
{
public:
	int num;
	My(int n = 0);
	My(My const & src);
	~My();
	My& operator=(My const & src);
};

std::ostream& operator<<(std::ostream &os, My const & src);

#endif
