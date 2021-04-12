#ifndef SPAN_HPP
# define SPAN_HPP

#include <set>
#include <iterator>
#include <iostream>
#include <vector>
#include <exception>

class Span
{
private:
	const unsigned int max;
	std::multiset<int> myset;
	Span();
	Span& operator=(Span const & src);

public:
	class FullSpanException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	class NotEnoughElementException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	class NotEnoughSpaceException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	Span(unsigned int size);
	Span(Span const & src);
	~Span();
	void			addNumber(int n);
	template <typename T>
	void	addNumber(T begin, T end);
	void			printStored() const;
	int				shortestSpan();
	int				longestSpan();
	unsigned int	getMax(void) const;
};

template <typename T>
void	Span::addNumber(T begin, T end)
{
	if (this->myset.size() == this->max)
		throw (FullSpanException());
	if (this->myset.size() + std::distance(begin, end) > this->max)
		throw (NotEnoughSpaceException());
	this->myset.insert(begin, end);
	return ;
}

#endif
