#include <iostream>
#include <string>
//#include <iomanip>
#include <sstream>

class Brain
{
public:
public:
	std::string identify(void) const;
	uintptr_t getAddress(const Brain &my) const;
};

class Human
{
private:
	const Brain my_brain;

public:
	std::string identify(void);
	const Brain& getBrain() const;
};

const Brain& Human::getBrain() const
{
	return (this->my_brain);
}

uintptr_t Brain::getAddress(const Brain &my) const
{
	uintptr_t addr = reinterpret_cast<uintptr_t>(&my);
	return (addr);
}


std::string Brain::identify(void) const
{
	uintptr_t uintaddr;
	std::string result;
	std::stringstream stream;

	uintaddr = getAddress(*this);
	stream << std::hex << uintaddr;
	result = "0x";
	result += stream.str();
	return (result);
}

std::string Human::identify(void)
{
	std::string temp;

	temp = this->my_brain.identify();
	return (temp);
}

int main()
{
	Human bob;
	
	std::cout << &bob << std::endl;
	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
}
