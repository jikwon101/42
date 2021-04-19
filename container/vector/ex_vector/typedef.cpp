#include <iostream>

template <typename T>
struct Base
{
	typedef T type_name;
};

template <typename T>
class long_iter_name : public Base<T>
{
private:
	typedef typename Base<T>::type_name type_name;
	typedef long_iter_name<type_name> iter;
	T temp;
	int num;
public:
	long_iter_name(int nbr = 0)
	{
		num = nbr;
	}
	long_iter_name(long_iter_name const & src)
	{
		this->num = src.num;
	}
	iter clone()
	{
		iter res(10);
		return (res);
	}
};

template <typename T>
class container 
{
private:
	int num;
public:
	typedef T type_name;
	typedef long_iter_name<type_name> iter;
	container(int nbr = 10)
	{
		num = nbr;
	}
	iter clone()
	{
		iter res(this->num);
		return (res);
	}
};

int main()
{
	container<int> a(40);
	container<int>::iter it = a.clone();
}
