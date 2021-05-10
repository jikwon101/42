template <typename T>
void print_info(T const& src)
{
	std::cout << "list has  [" << src.size() << "]\n";
}

template <typename T>
void print_type(T)
{
	std::cout << typeid(T).name() << std::endl;
}

template <typename T>
void print_list(const ft::list<T>& src)
{
	typename ft::list<T>::const_iterator it;
	
	std::cout << "[ ";
	for (it = src.begin() ; it != src.end() ; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "]" << std::endl;
}

template <>
void print_vector<ft::list<int> >(const ft::list<ft::list<int> >& src )
{
	for (size_t i = 0 ; i < src.size() ; i++)
	{
		std::cout << " + " ;
		print_vector(src[i]);
	}
}

template <typename T>
void print_it(T const & src)
{
	std::cout << "It indicates : " << *src << std::endl;
}
