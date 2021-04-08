#include "Simple.hpp"
#include "Extra.hpp"

int main()
{
	A a1(2);
	A a2(3);
	::swap(a1, a2);
	std::cout << "a1 = " << a1 << ", a2 = " << a2 << std::endl;
	std::cout << "min( a1, a2 ) = " << ::min(a1,a2) << std::endl;
	std::cout << "max( a1, a2 ) = " << ::max(a1,a2) << std::endl;	
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a,b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a,b) << std::endl;	

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min<std::string>(c,d) << std::endl;
	std::cout << "max( c, d ) = " << ::max<std::string>(c,d) << std::endl;

}
