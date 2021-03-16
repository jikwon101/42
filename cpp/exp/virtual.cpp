#include <iostream>


class Origin
{

public:
	int num;
	Origin();
	void print();
};

Origin::Origin()
{
	num = 3;
}
void Origin::print()
{
	std::cout << "This is origin" << num << " " << std::endl;
}


class Other : public Origin
{
public:
	void print();
};

void Other::print()
{
	std::cout << "THis is other" << num << std::endl;
}

int main()
{
	Origin origin;
	Other other;
	
	Origin *p1;
	Other *p2;
	p1 = &origin;
	p2 = &other;
	p1->print();
	std::cout << "--------------------\n";
	p2->print();
}
