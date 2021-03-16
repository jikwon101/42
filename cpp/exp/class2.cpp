#include <string>
#include <iostream>

class Animal
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;
	Animal();
};
Animal::Animal()
{
	num1 = 10;
	num2 = 20;
	num3 = 30;
}
class Pig : private Animal
{
public:
	Pig();
};

Pig::Pig()
{
	/*
	num1 += 10;
	num2 += 20;
	num3 += 30;
*/
}

int main()
{
	Pig pig;

	/*
	std::cout << pig.num1 << std::endl;
	std::cout << pig.num2 << std::endl;
	std::cout << pig.num3 << std::endl;
	*/
	//std::cout << pig.num2 << std::endl;
	//std::cout << pig.num3 << std::endl;
	
}
