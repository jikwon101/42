#include <iostream>

template <typename T>
class Span
{
private:
	int *arr;
public:
	Span(unsigned int n);
	void	addNumber(int nbr) throw (std::exception);
	int		shortestSpan() const throw (std::exception);
	int		longestSpan() const throw (std::exception);


	
}
int main()
{

}
