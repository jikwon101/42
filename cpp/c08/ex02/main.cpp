#include <iostream>
#include <stack>

template <typename T>
class MutantStack :  public std::stack<T>
{
public:
	MutantStack();
	virtual ~MutantStack();
	MutantStack(MutantStack<T> const & src);
	MutantStack<T>& operator=(MutantStack<T> const & src);

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	iterator begin(void);
	const_iterator begin(void) const;
	reverse_iterator rbegin(void);
	const_reverse_iterator rbegin(void) const;
	iterator end(void);
	const_iterator end(void) const;
	reverse_iterator rend(void);
	const_reverse_iterator rend(void) const;
	
};

template <typename T>
MutantStack<T>::MutantStack(){}
template <typename T>
MutantStack<T>::~MutantStack(){}
template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const & src){}
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack<T> const & src){}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{return (this->c.begin());
}
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{return (this->c.begin());
}
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)
{return (this->c.rbegin());
}
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin(void) const
{return (this->c.rbegin());}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{return (this->c.end());}
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{return (this->c.end());}
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void)
{return (this->c.rend());}
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend(void) const
{return (this->c.rend());}

int main()
{
	MutantStack<int> my;

	my.push(20);
	my.push(2);
	std::cout << my.top() << std::endl;
	MutantStack<int>::iterator it;
}
