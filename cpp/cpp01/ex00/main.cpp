#include "Pony.hpp"

void ponyOnTheStack(void)
{
	Pony stack_pony(1);
	stack_pony.Sing();
	std::cout << "Return (ponyOnTheStack)" << std::endl;
	return ;
}

void ponyOnTheHeap(void)
{
	Pony *heap_pony;
	
	heap_pony = new Pony(2);
	heap_pony->Sing();
	delete heap_pony;
	std::cout << "Return (ponyOnTheStack)" << std::endl;
	return ;
}

int main(void)
{
	std::cout << "Run pony on the Stack" << std::endl;
	ponyOnTheStack();
	std::cout << "----------------------" << std::endl;
	std::cout << "Run pony on the Heap" << std::endl;
	ponyOnTheHeap();
	
	return (0);
}
