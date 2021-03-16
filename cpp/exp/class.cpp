#include <iostream>
#include <string>

class Animal
{
private:
	std::string kind;
protected:
public:
	int num_of_legs;
	void	printnum();
	Animal();
	~Animal();
	void	setKind(std::string kind);
	std::string	getKind();
};
void Animal::printnum()
{
	std::cout << "print NUM" << std::endl;
}
Animal::Animal()
{
	std::cout << "This is Animal class" << std::endl;
	kind = "animal";
	num_of_legs = 2;
}

Animal::~Animal()
{
	std::cout << "Destructor of Animal class" << std::endl;
}

void Animal::setKind(std::string kind)
{
	this->kind = kind;
}

std::string Animal::getKind()
{
	return (this->kind);
}
class Pig : public Animal 
{
private:
	std::string type;
public:
	int color;
	Pig();
	~Pig();
};

Pig::Pig()
{
	std::cout << "This is Pig class" << std::endl;
	num_of_legs = 4;
	setKind("pig");
}

Pig::~Pig()
{
	std::cout << "Destructor of Pig class" << std::endl;
}

int main()
{
	Pig pig;
	//std::cout << _pig.num_of_legs << std::endl;
	//std::cout << _pig.getKind() << std::endl;
	pig.printnum();

}
