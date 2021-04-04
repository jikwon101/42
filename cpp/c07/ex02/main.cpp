#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
	T *arr;
	size_t arr_size;
public:
	Array();
	Array(unsigned int n);
	~Array();
	Array(Array<T> const  & src);
	T& operator[](int idx);
	Array<T>& operator=(Array<T> const & src);
	size_t size() const;
};

template <typename T>
Array<T>::Array()
{
	arr = 0;
	arr_size = 0;
}

template <typename T>
Array<T>::~Array()
{
	if (arr_size > 0)
		delete [] arr;
}
template <typename T>
T& Array<T>::operator[](int idx)
{
	if (idx < 0 || idx > this->arr_size - 1)
		throw (std::exception());
	return (this->arr[idx]);
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->arr_size = (size_t)n;
	arr = new T[n]();
}

template <typename T>
Array<T>::Array(Array<T> const & src)
{
	std::cout << "const by copy\n";
	this->arr_size = src.arr_size;
	this->arr = 0;
	if (src.arr_size > 0)
	{
		this->arr = new T[src.arr_size];
		for (int i = 0 ; i < src.arr_size ; i++)
		{
			this->arr[i] = src.arr[i];
		}
	}
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> const & src)
{
	std::cout << "operator=\n";
	if (this != &src)
	{
		if (this->arr_size > 0)
			delete [] arr;
		this->arr_size = src.arr_size;
		this->arr = new T[src.arr_size];
		for (int i = 0; i < src.arr_size ; i++)
		{
			this->arr[i] = src.arr[i];
		}
	}
	return (*this);
}

template <typename T>
size_t Array<T>::size(void) const
{
	return (arr_size);
}

int  main()
{
	Array<int> intR(5);
	for (size_t i = 0; i < intR.size() ; i++)
	{
		intR[i] = i;
		std::cout << intR[i] << " ";
	}
	std::cout << std::endl;

	Array<std::string> strR(3);
	for (size_t i = 0 ; i < strR.size() ; i++)
	{
		strR[i] = "hello";
		std::cout << strR[i] << " ";
	}
	std::cout << std::endl;

}
