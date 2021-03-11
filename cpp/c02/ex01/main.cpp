#include "Fixed.hpp"
#include <bitset>
int		main(void)
{
	Fixed		a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << a << std::endl;
	std::cout << "c is " << a << std::endl;
	std::cout << "d is " << a << std::endl;
	
	float t1 = 0.1;
	float t2 = 1;
	std::cout << std::bitset<32>(t1) << std::endl;
	std::cout << std::bitset<32>(t2) << std::endl;
	std::cout << std::bitset<32>(10) << std::endl;
	std::cout << std::bitset<32>(b.getRawBits()) << std::endl; //temp
	std::cout << "a is " << a.toInt() << " as interger" << std::endl;
	std::cout << "b is " << b.toInt() << " as interger" << std::endl;
	std::cout << "c is " << c.toInt() << " as interger" << std::endl;
	std::cout << "d is " << d.toInt() << " as interger" << std::endl;
	
	return 0;
}
