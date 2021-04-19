#include <iostream>


class T
{
private:
	int *arr;
public:
	T()
	{
		arr = 0;
		//arr = new int[10];
	}
	~T()
	{
		delete [] arr;
	}
};

int main()
{
	T a;

	std::cout << "return\n";
}
