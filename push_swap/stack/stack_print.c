#include "stack_print.h"

void	print(t_stack *st)
{
	t_node	*pos;
	int		cnt;

	cnt = st->size;
	printf("------------\nTOP\n");
	pos = st->head;
	while (cnt)
	{
		printf("%d \n", pos->data);
		pos = pos->next;
		cnt--;
	}
	printf("END\n------------\n");
}

void savef(int fd, t_stack *st)
{
	t_node *pos;
	int		cnt = st->size;

	char top[] = "------------\nTOP\n";
	char end[] = "END\n------------\n";
	write(fd, top, strlen(top));
	pos = st->head;
	while (cnt)
	{
		char *temp = ft_itoa(pos->data); 
		write(fd, temp, strlen(temp));
		write(fd, " \n", 2);
		pos = pos->next;
		cnt--;
	}
	write(fd, end, strlen(end));
}

void printpair(t_stack *a, t_stack *b)
{
	t_node *a_pos = a->head;
	t_node *b_pos = b->head;
	int a_size = a->size;
	int b_size = b->size;

	printf("------------\nTOP\n");
	while (a_size > b_size)
	{
		printf("%2d\n", a_pos->data);
		a_pos = a_pos->next;
		a_size--;
	}
	while (a_size < b_size)
	{
		printf("            %2d\n", b_pos->data);
		b_pos = b_pos->next;
		b_size--;
	}
	while (a_size && b_size)
	{
		printf("%2d          %2d\n", a_pos->data, b_pos->data);
		a_pos = a_pos->next;
		b_pos = b_pos->next;
		a_size--;
		b_size--;
	}
	printf("\033[0;33m");	//set yello color
	printf(" a           b\n");
	printf("\033[0m");		//reset color
	printf("END\n------------\n");
	usleep(500000);
}


