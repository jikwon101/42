#include "Array.hpp"
#include "Extra.hpp"

#define CL "\033[1m\33[36m"
#define RS "\033[0m"

int  main()
{
	Array<char> charArray;
	std::cout << charArray.size() << std::endl;
	print(charArray);

	std::cout << CL << "--------------------------\n" << RS;
	std::cout << CL << "|   Array<string>        |\n" << RS;
	std::cout << CL << "--------------------------\n" << RS;
	Array<std::string> strArray(3);
	std::cout << CL << "Array<string> strArray(3)" << RS << std::endl;
	init(strArray, "hi");
	print(strArray);
	
	std::cout << CL << "--------------------------\n" << RS;
	std::cout << CL << "|   Array<class A>       |\n" << RS;
	std::cout << CL << "--------------------------\n" << RS;
	Array<A> my(3);
	std::cout << CL << "Array<A> my(3)" << RS << std::endl;
	init(my, 39);
	print(my);

	std::cout << CL << "--------------------------\n" << RS;
	std::cout << CL << "|   Array<int>           |\n" << RS;
	std::cout << CL << "--------------------------\n" << RS;
	Array<int> intArray(5);
	std::cout << CL << "Array<int> intArray(5)" << RS << std::endl;
	init(intArray, 4);
	print(intArray);

	std::cout << CL << "Array<int> copyArray(intArray)" << RS << std::endl;
	Array<int> copyArray(intArray);
	std::cout << CL << "copyArray : " << RS << std::endl;
	print(copyArray);
	init(copyArray, 10);
	std::cout << CL << "copyArray : " << RS << std::endl;
	print(copyArray);
	std::cout << CL << "intArray : " << RS << std::endl;
	print(intArray);
	
	std::cout << CL << "Array<int> otherArray" << RS << std::endl;
	Array<int> otherArray;
	std::cout << CL << "otherArray : " << RS << std::endl;
	print(otherArray);
	std::cout << CL << "otherArray = intArray" << RS << std::endl;
	otherArray = intArray;
	std::cout << CL << "otherArray : " << RS << std::endl;
	print(otherArray);
	init(otherArray, 8);
	std::cout << CL << "otherArray : " << RS << std::endl;
	print(otherArray);
	std::cout << CL << "intArray : " << RS << std::endl;
	print(intArray);

	std::cout << CL << "--------------------------\n" << RS;
	std::cout << CL << "|   Const Array          |\n" << RS;
	std::cout << CL << "--------------------------\n" << RS;
	const Array<int> test(3);
	print(test);
	//init(test, 3);
	
	std::cout << CL << "--------------------------\n" << RS;
	std::cout << CL << "|   [] Error             |\n" << RS;
	std::cout << CL << "--------------------------\n" << RS;
	std::cout << CL << "Array<int> err(4)" << RS << std::endl;
	Array<int> err(4);
	init(err, 20);
	try
	{
		std::cout << CL << "err[-2]\n" << RS;
		err[-2];
	}
	catch (std::exception & err)
	{
		std::cout << err.what() << std::endl;
	}
	try
	{
		std::cout << CL << "err[10]\n" << RS;
		err[10];
	}
	catch (std::exception & err)
	{
		std::cout << err.what() << std::endl;
	}

}
