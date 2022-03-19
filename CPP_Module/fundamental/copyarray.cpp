#include <iostream>

class Test
{
public:
	int num[3];
};

void print_array(int *arr)
{
	for (int i = 0 ; i < 3 ; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
int main()
{
	Test t;

	t.num[0] = 1;
	t.num[1] = 2;
	t.num[2] = 3;
	print_array(t.num);

	Test n;

	n = t;
	print_array(n.num);

}
