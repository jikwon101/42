#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <deque>
#include <list>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), value);
	if  (it == container.end())
	{
		throw (std::exception());
	}
	return (it);
}

template <typename T>
void	printContainer(T &container)
{
	std::cout << "PRINT CONTAINER ----------------\n";
	typename T::iterator it;
	it = container.begin();
	for  (it = container.begin() ; it != container.end() ; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;
}

template <typename T>
void	testFind(T &container, int value)
{
	std::cout << "TEST FIND -----------------------\n";
	try
	{
		std::cout << "Trying to find " << value << std::endl;
		typename T::iterator res = easyfind(container, value);
		std::cout << *res << std::endl;
	}
	catch (std::exception & err)
	{
		std::cout << "Not Found\n";
	}
	std::cout << std::endl;
}

int main()
{
	// vector
	std::cout << "-----------------------\n";
	std::cout << "|    Vector           |\n";
	std::cout << "-----------------------\n";

	std::vector<int> v(1);
	v.push_back(2);
	v.push_back(8);
	v.push_back(23);

	printContainer(v);
	testFind(v, 2);
	testFind(v, 3);

	//deque : double ended queue
	std::cout << "-----------------------\n";
	std::cout << "|    Deque            |\n";
	std::cout << "-----------------------\n";
	std::deque<int> dq(1);
	dq.push_front(4);
	dq.push_back(10);
	dq.push_front(7);

	printContainer(dq);
	testFind(dq, 3);
	testFind(dq, 10);

	//list
	std::cout << "-----------------------\n";
	std::cout << "|    list             |\n";
	std::cout << "-----------------------\n";
	std::list<int> lst(1);
	lst.push_front(3);
	lst.push_back(10);
	lst.push_back(23);
	lst.push_back(2);
	
	printContainer(lst);
	testFind(lst, 5);
	testFind(lst, 4);

}
