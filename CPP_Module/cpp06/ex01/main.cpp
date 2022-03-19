#include "Data.hpp"

int main()
{
	srand(time(NULL));
	Data *res = deserialize(serialize());
	
	if (res)
	{
		std::cout << res->s1 << std::endl;
		std::cout << res->n << std::endl;
		std::cout << res->s2 << std::endl;
	}
}
