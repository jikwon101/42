#include "Simple.hpp"
#include "Extra.hpp"

template <typename T>
void test(T s1, T s2)
{
	std::cout << "[Before swap] first : " << s1 << "   second : " << s2 << std::endl;
	::swap(s1, s2);
	std::cout << "[After  swap] first : " << s1 << "   second : " << s2 << std::endl;
	std::cout << "min(" << s1 << " , " << s2 << ") = " << ::min(s1,s2) << std::endl;
	std::cout << "max(" << s1 << " , " << s2 << ") = " << ::max(s1,s2) << std::endl << std::endl;
}

int main()
{
	#ifndef TEST
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
	#endif

	#ifdef TEST
	std::cout << "------------------\n";
	std::cout << "TEST : float      \n";
	std::cout << "------------------\n";
	float f1 = 3.2;
	float f2 = -2.9;
	test(f1, f2);
		
	std::cout << "------------------\n";
	std::cout << "TEST : char       \n";
	std::cout << "------------------\n";
	char c1 = 'a';
	char c2 = 'b';
	test(c1, c2);

	std::cout << "------------------\n";
	std::cout << "TEST : class My   \n";
	std::cout << "------------------\n";
	My a1(2);
	My a2(3);
	test(a1, a2);

	#endif
}
