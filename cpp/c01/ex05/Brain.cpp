#include "Brain.hpp"

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
