#include <stdarg.h>
#include <unistd.h>

int width;
int dot;
int prec;
int spec;
int minus;
int data_len;
int printed_len;

# define BASE_LEN  ((spec == 'd') ? 10 : 16)
# define BASE ((spec == 'd') ? "0123456789" : "0123456789abcdef")

int ft_strlen(char *s)
{
	int i = 0;
	
	if (spec == 's' && dot == 1 && prec == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}
int ft_nbrlen(long long n)
{
	int i = 1;

	if (n == 0 && dot == 1 && prec == 0)
		return (0);
	while (n >= BASE_LEN)
	{
		i++;
		n = n / BASE_LEN;
	}
	return (i);
}
void ft_putchar(char c)
{
	write(1, &c, 1);
	printed_len++;
}
void ft_putstr(char *s)
{
	int i = 0;

	if (dot == 1 && prec == 0)
		return ;
	if (prec)
	{
		while (s[i] && i < prec)
			ft_putchar(s[i++]);
	}
	else
	{
		while (s[i])
			ft_putchar(s[i++]);
	}
}
void ft_putnbr(long long n)
{
	if (n == 0 && dot == 1 && prec == 0)
		return ;
	if (n >= BASE_LEN)
		ft_putnbr(n / BASE_LEN);
	ft_putchar(BASE[n % BASE_LEN]);
}
void print_space_zero(void)
{
	int cnt_space = 0;
	int cnt_zero = 0;

	if (spec == 's')
		cnt_space = (prec && prec < data_len) ? width - prec : width - data_len;
	else
	{
		cnt_space = (prec < data_len) ? width - data_len : width - prec;
		cnt_zero = prec - data_len;
	}
	while (0 < cnt_space--)
		ft_putchar(' ');
	if (spec == 'd' && minus == -1)
		ft_putchar ('-');
	while (0 < cnt_zero--)
		ft_putchar('0');
}
void	print_special(va_list ap)
{
	char *data_s;
	long long data_dx;

	if (spec == 's')
	{
		data_s = va_arg(ap, char *);
		data_s = (data_s == NULL) ? "(null)" : data_s;
		data_len = ft_strlen(data_s);
		print_space_zero();
		ft_putstr(data_s);
	}
	else
	{
		data_dx = (spec == 'd') ? (long long)va_arg(ap, int) : (long long)va_arg(ap, unsigned int);
		minus = (data_dx < 0) ? -1 : 1;
		data_len = (minus == -1) ? ft_nbrlen(-data_dx) : ft_nbrlen(data_dx);
		data_len = (minus == -1) ? data_len + 1 : data_len;
		prec = (minus == -1) ? prec + 1 : prec;
		print_space_zero();
		minus == -1 ? ft_putnbr(-data_dx) : ft_putnbr(data_dx);
	}
}
void check_info(char **str)
{
	while ('0' <= **str && **str <= '9')
	{
		width = width * 10 + **str - '0';
		(*str)++;
	}
	if (**str == '.')
	{
		dot = 1;
		(*str)++;
	}
	while ('0' <= **str && **str <= '9')
	{
		prec = prec * 10 + **str - '0';
		(*str)++;
	}
	if (**str == 's' || **str == 'd' || **str == 'x')
		spec = **str;
}

void init_info(void)
{
	width = 0;
	dot = 0;
	prec = 0;
	spec = 0;
	minus = 0;
	data_len = 0;
}

int ft_print(char *str, ...)
{
	va_list ap;

	printed_len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			check_info(&str);
			print_special(ap);
			str++;
		}
		else
		{
			ft_putchar(*str);
			str++;
		}
		init_info();
	}
	va_end(ap);
	return (printed_len);
}

#include <stdio.h>
int main()
{
	ft_print("|%d|\n", -2147483647);
	printf("|%d|\n", -2147483647);

	ft_print("|%3.3d|\n", 0);
	printf("|%3.3d|\n", 0);
	ft_print("|%7.3d|\n", 0);
	printf("|%7.3d|\n", 0);
	ft_print("|%3.7d|\n", 0);
	printf("|%3.7d|\n", 0);
	ft_print("|%7.7d|\n", 0);
	printf("|%7.7d|\n", 0);

	printf("-----------------\n");
	ft_print("|%3.3d|\n", -12345);
	printf("|%3.3d|\n", -12345);
	ft_print("|%7.3d|\n", -12345);
	printf("|%7.3d|\n", -12345);
	ft_print("|%3.7d|\n", -12345);
	printf("|%3.7d|\n", -12345);
	ft_print("|%7.7d|\n", -12345);
	printf("|%7.7d|\n", -12345);

	printf("-----------------\n");
	ft_print("|%3.3d|\n", 12345);
	printf("|%3.3d|\n", 12345);
	ft_print("|%7.3d|\n", 12345);
	printf("|%7.3d|\n", 12345);
	ft_print("|%3.7d|\n", 12345);
	printf("|%3.7d|\n", 12345);
	ft_print("|%7.7d|\n", 12345);
	printf("|%7.7d|\n", 12345);

	printf("-----------------\n");
	ft_print("|%7s|\n", "12345");
	printf("|%7s|\n", "12345");
	ft_print("|%3s|\n", "12345");
	printf("|%3s|\n", "12345");
	ft_print("|%7.1s|\n", "12345");
	printf("|%7.1s|\n", "12345");
	ft_print("|%3.1s|\n", "12345");
	printf("|%3.1s|\n", "12345");
	ft_print("|%7.7s|\n", "12345");
	printf("|%7.7s|\n", "12345");
	ft_print("|%3.7s|\n", "12345");
	printf("|%3.7s|\n", "12345");

	printf("-----------------\n");
}
