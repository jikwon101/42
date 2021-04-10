#include <iostream>

class T
{
public:
int t;
};

class M1 :virtual public T
{
public:
int m1;
};

class M2 : virtual public T
{
public:
int m2;
};
class B : public M1, public M2
{
public:
	int b;
};
int main()
{
	B *p = new B;
	std::cout << "B  : " << p << std::endl;
	std::cout << "t  : " << &(p->t) << std::endl;
	std::cout << "m1 : " << &(p->m1) << std::endl;
	std::cout << "m2 : " << &(p->m2) << std::endl;
	std::cout << "b  : " << &(p->b) << std::endl;
}
