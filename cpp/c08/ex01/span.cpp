#include "span.hpp"

/* 
** exception 
*/
const char *Span::FullSpanException::what(void) const throw()
{
	return ("FullSpanException");
}
const char *Span::NotEnoughElementException::what(void) const throw()
{
	return ("NotEnoughElementException");
}

const char *Span::NotEnoughSpaceException::what(void) const throw()
{
	return ("NotEnoughSpaceException");
}

/*
** Coplien's form
*/
Span::Span():max(0){}
Span::Span(unsigned int size) : max(size)
{
	std::cout << "<size : " << size << "> object is created\n";
}
Span::Span(Span const & src) : max(src.max) 
{
	this->myset = src.myset;
}

Span& Span::operator=(Span const & src) 
{
	if (this != &src)
		this->myset = src.myset;
	return (*this);
}

Span::~Span(){}


/*
** Getter
*/
unsigned int	Span::getMax(void) const
{
	return (max);
}


/*
** Member function
*/
void	Span::printStored(void) const
{
	std::multiset<int>::const_iterator pos;
	std::multiset<int>::const_iterator end;

	std::cout << "PRINT STORED -------------\n";
	pos = this->myset.begin();
	end = this->myset.end();
	while (pos != end)
	{
		std::cout << *pos << " ";
		pos++;
	}
	std::cout << std::endl;
}

int		Span::shortestSpan()
{
	std::multiset<int>::iterator pos_begin;
	std::multiset<int>::iterator pos_next;
	
	if (myset.size() < 2)
		throw (NotEnoughElementException());
	pos_begin = myset.begin();
	pos_next = myset.begin();
	pos_next++;
	return (*pos_next - *pos_begin);
}

int		Span::longestSpan() 
{
	std::multiset<int>::iterator pos_begin;
	std::multiset<int>::iterator pos_end;

	if (myset.size() < 2)
		throw (NotEnoughElementException());
	pos_begin = myset.begin();
	pos_end = myset.end();
	--pos_end;
	return (*pos_end - *pos_begin);
}

void	Span::addNumber(int n) 
{
	if (this->myset.size() == this->max)
		throw (FullSpanException());
	this->myset.insert(n);
	return ;
}
