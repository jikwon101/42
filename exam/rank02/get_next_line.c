#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char *ft_strjoin(char *s1, char *s2)
{
	int cnt;
	char *res;
	int i;

	i = 0;
	cnt = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(cnt + 1);
	if (res == NULL)
		return (NULL);
	res[cnt] = '\0';
	while (*s1)
		res[i++] = *(s1++);
	while (*s2)
		res[i++] = *(s2++);
	return (res);
}

int get_next_line(char **line)
{
	int size;
	char buf[2];
	char *store;
	char *temp;

	size = 1;
	buf[size] = '\0';
	store = ft_strjoin("", "");
	while (size && buf[0] != '\n')
	{
		size = read(0, buf, 1);
		if (size == 0)
			break;
		if (buf[0] != '\n')
		{
			temp = ft_strjoin(store, buf);
			if (temp == NULL)
				return (-1);
			else
				free(store);
			store = temp;
		}
	}
	*line = store;
	return (size);
}
