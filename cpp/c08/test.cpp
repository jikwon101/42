#include <iostream>

class T 
{
	public:
	int a;
	void funt()
	{
		std::cout << "func\n";
	}
	T()
	{
		std::cout << "T\n";
	}

};

class M1 : public T
{
	public:
	M1()
	{
		std::cout << "M1\n";
	}

};

class M2 : public T
{
	public:
	M2()
	{
		std::cout << "M2\n";
	}

};

class B : public T, public M1, public M2
{
public:
	B()
	{
		std::cout << "B\n";
	}
};

int main()
{
	B b;
}
