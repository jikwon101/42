#include "check_argument_sub.h"

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_under_min(char *str, int len)
{
	int		res;
	char	*minint;

	res = 0;
	minint = ft_strdup("-2147483648");
	if (!minint)
		errorexit("Error : Malloc error\n");
	if (*str && *str == '-')
		str++;
	while (*str && *str == '0')
		str++;
	if (len > 11 || (len == 11 && ft_strcmp(minint, str) < 0))
		res = 1;
	free(minint);
	return (res);
}

int	is_over_max(char *str, int len)
{
	int		plus;
	int		res;
	char	*maxint;

	plus = 0;
	res = 0;
	maxint = ft_strdup("2147483647");
	if (!maxint)
		errorexit("Error : Malloc error\n");
	if (*str && *str == '+')
	{
		str++;
		plus = 1;
	}
	while (*str && *str == '0')
		str++;
	if (plus
		&& (len > 11 || (len == 11 && ft_strcmp(maxint, str + 1) < 0)))
		res = 1;
	else if ((len > 10 || (len == 10 && ft_strcmp(maxint, str) < 0)))
		res = 1;
	free(maxint);
	return (res);
}

int	isn_int_range(char *str)
{
	int	res;
	int	len;

	res = 0;
	len = ft_strlen(str);
	if (str[0] == '-')
		res = is_under_min(str, len);
	else
		res = is_over_max(str, len);
	return (res);
}

int	is_duplicate(int *data, int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (data[i] == n)
			return (1);
		i++;
	}
	return (0);
}
