
template <typename T>
void print_info(T const& src)
{
	std::cout << "size [" << src.size() << "], cap [" << src.capacity() << "]\n";
}

template <typename T>
void print_type(T)
{
	std::cout << typeid(T).name() << std::endl;
}

void print(std::string const& src)
{
	std::cout << src << std::endl;
}

template <typename T>
void print_vector(const ft::vector<T>& src)
{
	typename ft::vector<T>::const_iterator it;
	
	std::cout << "[ ";
	for (it = src.begin() ; it != src.end() ; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "]" << std::endl;
}

template <>
void print_vector<ft::vector<int> >(const ft::vector<ft::vector<int> >& src )
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
	std::cout << "It contains : " << *src << std::endl;
}

