#include "three.h"
int main()
{
	char *test = (char *)malloc(4);
	free(test);
	free(test);
}
