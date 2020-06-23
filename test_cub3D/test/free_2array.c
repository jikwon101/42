#include <stdlib.h>
void ft_free(char **tgr)
{
	int i;

	i = 0;
	while (tgr[i])
	{
		free(tgr[i]);
		i++;
	}
	free(tgr);
}
int main()
{
	char **result;
	int i =0;
	int count = 2;

	result = (char **)malloc(sizeof(char *) * (count + 1));
	result[count] = NULL;
	while (i < count)
	{
		result[i] = (char *)malloc(sizeof(char) * (4 + 1));
		result[i][4] = '\0';
		i++;
	}
	ft_free(result);
	return (0);
}
