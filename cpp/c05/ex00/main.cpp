#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("K", 2);

	std::cout << b;
	b.upGrade();
	std::cout << b;
	b.upGrade();
	std::cout << b;
}
