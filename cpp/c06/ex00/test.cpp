#include <iostream>
#include <unistd.h>
class A
{
int a;
};

class B : public A
{
int b;
};
class C
{
char c;
};

class BB : public B, public C
{
const char str[5] = "abcd";
};
int main()
{
	B b;
	BB bb;
	
	A &p = bb;
	A *p2 = &bb;

}

