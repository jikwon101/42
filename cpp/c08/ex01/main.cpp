#include <set>
#include <iterator>
#include <iostream>
#include <vector>
#include <exception>

class Span
{
private:
	const unsigned int max;
	std::set<int> myset;
	Span();
	Span& operator=(Span const & src);
public:
	class FullSpanException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	class NotEnoughException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	Span(unsigned int size);
	Span(Span const & src);
	~Span();
	void	addNumber(int n) throw (std::exception);
	template <typename T> void	addNumber(T begin, T end) throw (std::exception);
	void	printStored() const;
	int		shortestSpan() throw (std::exception);
	int		longestSpan() throw (std::exception);
	int		getMax(void) const;
};

const char *Span::FullSpanException::what(void) const throw()
{
	return ("FullSpanException");
}
const char *Span::NotEnoughException::what(void) const throw()
{
	return ("NotEnoughException");
}

Span::Span():max(0){}
Span::Span(unsigned int size) : max(size) {}
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


void	Span::printStored(void) const
{
	std::set<int>::iterator pos;
	std::set<int>::iterator end;

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

int		Span::getMax(void) const
{
	return (max);
}

int		Span::shortestSpan() throw (std::exception)
{
	std::set<int>::iterator pos_begin;
	std::set<int>::iterator pos_next;
	
	if (myset.size() < 2)
		throw (NotEnoughException());
	pos_begin = myset.begin();
	pos_next = myset.begin();
	pos_next++;
	return (*pos_next - *pos_begin);
}

int		Span::longestSpan() throw (std::exception)
{
	std::set<int>::iterator pos_begin;
	std::set<int>::iterator pos_end;

	if (myset.size() < 2)
		throw (NotEnoughException());
	pos_begin = myset.begin();
	pos_end = myset.end();
	--pos_end;
	return (*pos_end - *pos_begin);
}

void	Span::addNumber(int n) throw (std::exception)
{
	if (this->myset.size() == this->max)
		throw (FullSpanException());
	this->myset.insert(n);
	return ;
}

template <typename T>
void	Span::addNumber(T begin, T end) throw (std::exception)
{
	if (this->myset.size() == this->max)
		throw (FullSpanException());
	this->myset.insert(begin, end);
	return ;
}

int main()
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	Span my(2);
	try
	{
		my.addNumber(3);
		my.printStored();
		std::cout << my.shortestSpan() << std::endl;
		std::cout << my.longestSpan() << std::endl;
	}
	catch(std::exception & err)
	{
		std::cout << "Error : " << err.what() << std::endl;
	}

	Span my1(3);
	try
	{
		std::vector<int> v(1, 9);
		v.push_back(3);
		v.push_back(10);
		v.push_back(2);

		my1.addNumber(v.begin(), v.end());
		my1.printStored();
	}
	catch(...)
	{
		std::cout << "Add Error\n";
	}
	return (0);
}
