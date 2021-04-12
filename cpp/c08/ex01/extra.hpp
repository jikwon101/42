#ifndef EXTRA_HPP
# define EXTRA_HPP

#include <set>
#include <iterator>
#include <iostream>
#include <vector>
#include <exception>

class v_Span
{
private:
	const unsigned int max;
	std::vector<int> myset;
	v_Span();
	v_Span& operator=(v_Span const & src);

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
	v_Span(unsigned int size);
	v_Span(v_Span const & src);
	~v_Span();
	void			addNumber(int n);
	template <typename T>  void	addNumber(T begin, T end);
	void			printStored() const;
	int				shortestSpan();
	int				longestSpan();
	unsigned int	getMax(void) const;
};

template <typename T>
void	v_Span::addNumber(T begin, T end)
{
	if (this->myset.size() == this->max)
		throw (FullSpanException());
	if (this->myset.size() + std::distance(begin, end) > this->max)
		throw (NotEnoughSpaceException());
	this->myset.insert(this->myset.end(), begin, end);
	sort(this->myset.begin(), this->myset.end());
	return ;
}

#endif
