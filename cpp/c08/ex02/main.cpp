#include "mutantstack.hpp"

# define CL "\033[1m\033[36m"
# define RS "\033[0m"

int main()
{
	const MutantStack<int> cstack;

	MutantStack<int>::const_iterator t1;
	t1 = cstack.begin();
	//MutantStack<int>::iterator t1 = cstack.begin();

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << CL << "mstack.top()\n" << RS;
	std::cout << mstack.top() << std::endl;
	std::cout << "----------------\n";


	mstack.pop();
	std::cout << CL << "mstack.size()\n" << RS;
	std::cout << mstack.size() << std::endl;
	std::cout << "----------------\n";


	mstack.push(3);
	mstack.push(9);
	mstack.push(73);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << CL << "mstack print\n" << RS;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "----------------\n";

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	std::cout << CL << "mstack print reverse \n" << RS;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::cout << "----------------\n";
	
	
	std::stack<int> s1(mstack);
	std::cout << CL << "Stack top \n" << RS;
	while (s1.size())
	{
		std::cout << (s1.top()) << std::endl;
		s1.pop();
	}
	std::cout << "----------------\n";
	

	std::cout << CL << "operator=\n" << RS;
	MutantStack<int> s;
	s = mstack;
	MutantStack<int>::iterator it1 = s.begin();
	MutantStack<int>::iterator ite1 = s.end();
	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}


	return 0;

}
