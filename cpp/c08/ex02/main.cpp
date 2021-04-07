#include <iostream>
#include <stack>

template <typename T>
class MutantStack :  public std::stack<T>
{
public:
	MutantStack();
	~MutantStack();
	MutantStack(MutantStack<T> const & src);
	MutantStack<T>& operator=(MutantStack<T> const & src);
	
};

int main()
{
	MutantStack<int> my;

	my.push(20);
	my.push(2);
	std::cout << my.top() << std::endl;
	MutantStack<int>::iterator it;
	it.b = 3;
	std::cout << it.b << std::endl;

}
