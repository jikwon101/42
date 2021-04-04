#include "Generator.hpp"
#include "Identify.hpp"

/*
class Base
{
public:
	virtual ~Base(){}
};

class A : public Base
{
public:
	virtual ~A()
	{
		std::cout << "A";
	}
};

class B : public Base
{
public:
	virtual ~B()
	{
		std::cout << "B";
	}

};

class C : public Base
{
public:
	virtual ~C()
	{
		std::cout << "C";
	}

};

Base *generate(void)
{
	int num;

	num = rand() % 3;
	std::cout << num << std::endl;
	if (num == 0)
		return (new A);
	else if (num == 1)
		return (new B);
	return (new C);
}

void	identify_from_pointer(Base *p)
{
	void *ptr;

	if ((ptr = dynamic_cast<A *>(p)) != 0)
		std::cout << "A\n";
	else if ((ptr = dynamic_cast<B *>(p)) != 0)
		std::cout << "B\n";
	else if ((ptr = dynamic_cast<C *>(p)) != 0)
		std::cout << "C\n";
}

void 	identify_from_reference(Base & p)
{
	void *ptr;

	if ((ptr = dynamic_cast<A *>(&p)) != 0)
		std::cout << "A\n";
	else if ((ptr = dynamic_cast<B *>(&p)) != 0)
		std::cout << "B\n";
	else if ((ptr = dynamic_cast<C *>(&p)) != 0)
		std::cout << "C\n";
}
*/
int main()
{
	Base *res;

	srand(time(NULL));
	res = generate();
	identify_from_pointer(res);
	identify_from_reference(*res);
}
