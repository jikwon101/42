template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const & src)
{
	std::cout << src.size() << std::endl;
	this->c = src.c;
	(void)src;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack<T> const & src)
{
	this->c = src.c;
	(void)src;
	return (*this);
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{return (this->c.begin());}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{return (this->c.begin());}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)
{return (this->c.rbegin());}

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
