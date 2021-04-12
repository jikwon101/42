#include "extra.hpp"

/* 
** exception 
*/
const char *v_Span::FullSpanException::what(void) const throw()
{
	return ("FullSpanException");
}
const char *v_Span::NotEnoughElementException::what(void) const throw()
{
	return ("NotEnoughElementException");
}
const char *v_Span::NotEnoughSpaceException::what(void) const throw()
{
	return ("NotEnoughSpaceException");
}

/*
** Coplien's form
*/
v_Span::v_Span():max(0){}
v_Span::v_Span(unsigned int size) : max(size) 
{
	std::cout << "<size : " << size << "> object is created\n";
}
v_Span::v_Span(v_Span const & src) : max(src.max) 
{
	this->myset = src.myset;
}

v_Span& v_Span::operator=(v_Span const & src) 
{
	if (this != &src)
		this->myset = src.myset;
	return (*this);
}

v_Span::~v_Span(){}


/*
** Getter
*/
unsigned int	v_Span::getMax(void) const
{
	return (max);
}


/*
** Member function
*/
void	v_Span::printStored(void) const
{
	std::vector<int>::const_iterator pos;
	std::vector<int>::const_iterator pos_end;

	std::cout << "PRINT STORED -------------\n";
	pos = myset.begin();
	pos_end = myset.end();
	while (pos != pos_end)
	{
		std::cout << *pos << " ";
		pos++;
	}
	std::cout << std::endl;
}

int		v_Span::shortestSpan()
{
	std::vector<int>::iterator pos_begin;
	std::vector<int>::iterator pos_next;
	
	if (myset.size() < 2)
		throw (NotEnoughElementException());
	pos_begin = myset.begin();
	pos_next = myset.begin();
	pos_next++;
	return (*pos_next - *pos_begin);
}

int		v_Span::longestSpan()
{
	std::vector<int>::iterator pos_begin;
	std::vector<int>::iterator pos_end;

	if (myset.size() < 2)
		throw (NotEnoughElementException());
	pos_begin = myset.begin();
	pos_end = myset.end();
	--pos_end;
	return (*pos_end - *pos_begin);
}

void	v_Span::addNumber(int n)
{
	if (this->myset.size() == this->max)
		throw (FullSpanException());
	this->myset.push_back(n);
	sort(this->myset.begin(), this->myset.end());
	return ;
}
