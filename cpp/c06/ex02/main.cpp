#include "Generator.hpp"
#include "Identify.hpp"

int main()
{
	Base *res;

	srand(time(NULL));
	res = generate();
	identify_from_pointer(res);
	identify_from_reference(*res);
}
