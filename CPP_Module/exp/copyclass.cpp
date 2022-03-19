#include <iostream>
#include <string>


class Pet
{
public:
	virtual void bark() = 0;	
};

class Dog : public Pet
{
public:
	virtual void bark();
};

class Human
{
public:
	Pet **pet;
};

void Dog::bark()
{
	std::cout << "BARRRR...." << std::endl;
}

int main()
{
	Human *me = new Human;

	Pet *dog1 = new Dog;
	Pet *dog2 = new Dog;
	
	me->pet = new Pet*[2];
	me->pet[0] = new Dog(*dog1); 
	Human *jj = new Human;

}
