#include "span.hpp"
#include "extra.hpp"

# define CL "\033[1m\033[36m"
# define RS "\033[0m"

int main()
{
	std::cout << CL <<"TEST 1 ----------------\n" << RS;
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(3);
	sp.printStored();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	std::cout << CL <<"TEST 2  --------------\n" << RS;
	Span my(2);
	try
	{
		my.addNumber(3);
		my.printStored();
		std::cout << CL << "[shortestSpan()] > " <<RS;
		std::cout << my.shortestSpan() << std::endl;
	}
	catch(std::exception & err)
	{
		std::cout << "Error : " << err.what() << std::endl;
	}
	try
	{
		std::cout << CL << "[longestSpan()] > " <<RS;
		std::cout << my.longestSpan() << std::endl;
	}
	catch(std::exception & err)
	{
		std::cout << "Error : " << err.what() << std::endl;
	}

	std::cout << CL <<"TEST 3  --------------\n" << RS;
	Span sp2(5);
	try
	{
		std::vector<int> v(1, 9);
		v.push_back(3);
		v.push_back(10);
		sp2.addNumber(v.begin(), v.end());
		sp2.printStored();
		v.push_back(2);
		v.push_back(19);
		v.push_back(33);
		sp2.addNumber(v.begin(), v.end());
		sp2.printStored();

	}
	catch(std::exception &err)
	{
		std::cout << "Error : " << err.what() << std::endl;
	}

	std::cout << CL <<"TEST 4  --------------\n" << RS;
	v_Span test(7);
	try
	{
		int arr[] = {1,2,3,4,5};
		test.addNumber(arr, arr+ 5);
		test.printStored();
		/*
		std::vector<int> v(1, 9);
		v.push_back(2);
		v.push_back(10);
		v.push_back(2);
		std::cout << "HERE\n";
		test.addNumber(v.begin(), v.end());
		test.printStored();
		v.push_back(2);
		v.push_back(10);
		v.push_back(19);
		test.addNumber(v.begin(), v.end());
		test.printStored();*/
	}
	catch(std::exception &err)
	{
		std::cout << "Error : " << err.what() << std::endl;
	}
	return (0);
}
