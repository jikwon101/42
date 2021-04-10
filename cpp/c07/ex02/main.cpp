#include "Array.hpp"

int  main()
{
	Array<int> intR(5);
	for (size_t i = 0; i < intR.size() ; i++)
	{
		intR[i] = i;
		std::cout << intR[i] << " ";
	}
	std::cout << std::endl;

	Array<std::string> strR(3);
	for (size_t i = 0 ; i < strR.size() ; i++)
	{
		strR[i] = "hello";
		std::cout << strR[i] << " ";
	}
	std::cout << std::endl;


}
