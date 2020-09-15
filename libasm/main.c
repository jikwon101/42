/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:25:43 by lmartin           #+#    #+#             */
/*   Updated: 2020/09/15 16:15:27 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "libasm.h"

void		test_ft_strdup()
{
	printf("\x1b[32mft_strdup :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strdup(""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup(""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strdup("toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup("toto"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strdup("0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup("0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	//printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup(NULL));
}

void		test_ft_read()
{
	int			fd;
	char		buffer[100];
	char		show[100];
	ssize_t		ret;

	printf("\x1b[32mft_read:\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'open(\"main.c\", O_RDONLY)' '' '0'\x1b[0m\n");
	fd = open("testlib.c", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("testlib.c", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'open(\"Makefile\", O_RDONLY)' '' '50'\x1b[0m\n");
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, buffer, 50);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 50));
	close(fd);
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, buffer, 50);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 50));
	close(fd);
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'open(\"dontexist\", O_RDONLY)' '' '10'\x1b[0m\n");
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'open(\"testlib.c\", O_RDONLY)' 'NULL' '10'\x1b[0m\n");
	fd = open("testlib.c", O_RDONLY);
	ret = read(fd, NULL, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", ret);
	close(fd);
	fd = open("testlib.c", O_RDONLY);
	ret = read(fd, NULL, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ret);
	close(fd);
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'42' '' '10'\x1b[0m\n");
	ret = read(42, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	ret = read(42, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("empty_file", O_RDONLY | O_TRUNC | O_CREAT, 0777);
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'open(\"empty_file\", O_RDONLY | O_TRUNC | O_CREAT, 0777)' '' '10'\x1b[0m\n");
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	remove("empty_file");
}

void		test_ft_write()
{
	int			fd;
	char		buffer[100];

	printf("\x1b[32mft_write :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'1' '' '0'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "", 0));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "", 0));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'1' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 4));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'1' 'toto' '2'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 2));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 2));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'1' 'toto' '40'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 40));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 40));
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'1' 'NULL' '6'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, NULL, 6));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, NULL, 6));
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'0' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(0, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(0, "toto", 4));
	printf("	\x1b[34m[7]\x1b[0m \x1b[36m'42' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(42, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(42, "toto", 4));
	printf("	\x1b[34m[8]\x1b[0m \x1b[36m'-1' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(-1, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(-1, "toto", 4));
	fd = open("ft_write_test", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	printf("	\x1b[34m[9]\x1b[0m \x1b[36m'open(\"ft_write_test\", O_WRONLY | O_TRUNC | O_CREAT)' '<whichlib.h> toto' '15'\x1b[0m\n");
	write(fd, "<unistd.h> toto", 15);
	ft_write(fd, "<libasm.h> toto", 15);
	close(fd);
	fd = open("ft_write_test", O_RDONLY);
	read(fd, buffer, 15);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %s\n", buffer);
	read(fd, buffer, 15);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", buffer);
	close(fd);
	remove("ft_write_test");
}

void		test_ft_strcmp()
{
	printf("\x1b[32mft_strcmp :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'' ''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("", ""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("", ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'toto' 'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("toto", "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("toto", "toto"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'toto' ''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("toto", ""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("toto", ""));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'' 'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %d\n", strcmp("", "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("", "toto"));
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'tototest' 'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("tototest", "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("tototest", "toto"));
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'bbbonjour' 'bbonjour'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %d\n", strcmp("bbbonjour", "bbonjour"));
	printf("		\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("bbbonjour", "bbonjour"));
	printf("	\x1b[34m[7]\x1b[0m \x1b[36m'NULL' 'bbonjour'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp(NULL, "bbonjour"));
	printf("	\x1b[34m[8]\x1b[0m \x1b[36m'NULL' 'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp(NULL, NULL));
	printf("	\x1b[34m[9]\x1b[0m \x1b[36m'' 'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("", NULL));
}

void		test_ft_strcpy()
{
	char	dst[100];
	printf("\x1b[32mft_strcpy :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, ""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, "toto"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, "0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, NULL));
}

void		test_ft_strlen()
{
	printf("\x1b[32mft_strlen :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen(""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen(""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'    '\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen("    "));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen("    "));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen("0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen("0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen(NULL));
}

void		test_ft_atoi_base(void)
{
	printf("\x1b[32mft_atoi_base :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m42, [0123456789]\x1b[0m\n");
	printf("		\x1b[33m<  int   >\x1b[0m  %d\n", 42);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_atoi_base("42", "0123456789"));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m0, [0123456789]\x1b[0m\n");
	printf("		\x1b[33m<  int   >\x1b[0m  %d\n", 0);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_atoi_base("0", "0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m-0, [0123456789]\x1b[0m\n");
	printf("		\x1b[33m<  int   >\x1b[0m  %d\n", -0);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_atoi_base("-0", "0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m--42, [0123456789]\x1b[0m\n");
	printf("		\x1b[33m<  int   >\x1b[0m  %d\n", 42);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_atoi_base("--42", "0123456789"));

	printf("	\x1b[34m[3]\x1b[0m \x1b[36m--++-+42, [0123456789]\x1b[0m\n");
	printf("		\x1b[33m<  int   >\x1b[0m  %d\n", -42);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_atoi_base("--++-+42", "0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m-1215415478, [0123456789]\x1b[0m\n");
	printf("		\x1b[33m<  int   >\x1b[0m  %d\n", -1215415478);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_atoi_base("-1215415478", "0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m-2147483649, [0123456789]\x1b[0m\n");
	printf("		\x1b[33m<  int   >\x1b[0m  %d\n", -2147483649);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_atoi_base("-2147483649", "0123456789"));

	printf("	\x1b[34m[3]\x1b[0m \x1b[36m2a, [0123456789abcdef]\x1b[0m\n");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_atoi_base("2a", "0123456789abcdef"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36mff, [0123456789abcdef]\x1b[0m\n");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_atoi_base("ff", "0123456789abcdef"));

	printf("	\x1b[34m[3]\x1b[0m \x1b[36mponey, [poney]\x1b[0m\n");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_atoi_base("poney", "poney"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36mdamage, [invalid]\x1b[0m\n");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_atoi_base("damage", "invalid"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36mdamage, [soup]\x1b[0m\n");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_atoi_base("damage", "soup"));

	printf("	\x1b[34m[3]\x1b[0m \x1b[36m|    +42|, [0123456789]\x1b[0m\n");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_atoi_base("    +42", "0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m|    -42|, [0123456789]\x1b[0m\n");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_atoi_base("    -42", "0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m| \\t\\n\\r\\v\\f 42|, [0123456789]\x1b[0m\n");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_atoi_base(" \t\n\r\v\f 42", "0123456789"));
}

void		print_list(t_list *begin)
{
		t_list *here;

		here = begin;
		while (here != NULL)
		{
			printf("%s / ", here->data);
			here = here->next;
		}
		printf("\n");
		return ;
	
}

void	free_list(t_list **begin)
{
	t_list *here;
	t_list *temp;

	here = *begin;
	while (here != NULL)
	{
		if (here->data != NULL)
			free(here->data);
		temp = here;
		here = here->next;
		free(temp);
	}
	return ;
}
void		test_ft_list_push_front(void)
{
	printf("\x1b[32mft_list_push_front:\x1b[0m\n");
	t_list *begin = NULL;
	ft_list_push_front(&begin, strdup("hi"));
	ft_list_push_front(&begin, strdup("hello"));
	ft_list_push_front(&begin, strdup("nihao"));
	ft_list_push_front(&begin, strdup("annyong"));
	ft_list_push_front(&begin, strdup("apa kabar"));
	printf("	\x1b[34m[1]\x1b[36m \x1b NULL\x1b[0m\n");
	printf("	   \x1b[0m \x1b[36mhi\x1b[0m\n");
	printf("	   \x1b[0m \x1b[36mhello\x1b[0m\n");
	printf("	   \x1b[0m \x1b[36mnihao\x1b[0m\n");
	printf("	   \x1b[0m \x1b[36mannyong\x1b[0m\n");
	printf("	   \x1b[0m \x1b[36mapa kabar\x1b[0m\n");
	printf("		\x1b[33m<libasm.h>\x1b[0m  ");
	print_list(begin);
	free_list(&begin);
	begin = NULL;
	char input1[100];
	char input2[100];
	char input3[100];
	char input4[100];
	printf("	\x1b[34m[2]\x1b[36m \x1b type your first data : \x1b[0m");

	scanf("%s", input1);
	ft_list_push_front(&begin, strdup(input1));


	printf("	  \x1b[0m \x1b[36m type your second data : \x1b[0m");
	scanf("%s", input2);
	ft_list_push_front(&begin, strdup(input2));
	

	printf("	  \x1b[0m \x1b[36m type your third data : \x1b[0m");
	scanf("%s", input3);
	ft_list_push_front(&begin, strdup(input3));
	
	printf("	  \x1b[0m \x1b[36m type your last data : \x1b[0m");
	scanf("%s", input4);
	ft_list_push_front(&begin, strdup(input4));

	printf("		\x1b[33m<libasm.h>\x1b[0m  ");
	print_list(begin);
	free_list(&begin);
	
}

void		test_ft_list_size(void)
{
	printf("\x1b[32mft_list_size:\x1b[0m\n");
	t_list *begin = NULL;
	ft_list_push_front(&begin, strdup("10"));
	ft_list_push_front(&begin, strdup("9"));
	ft_list_push_front(&begin, strdup("8"));
	ft_list_push_front(&begin, strdup("7"));
	ft_list_push_front(&begin, strdup("6"));
	ft_list_push_front(&begin, strdup("5"));
	ft_list_push_front(&begin, strdup("4"));
	ft_list_push_front(&begin, strdup("3"));
	ft_list_push_front(&begin, strdup("2"));
	ft_list_push_front(&begin, strdup("1"));

	printf("	\x1b[34m[1]\x1b[36m \x1b 1,2,3,4,5,6,7,8,10 \x1b[0m\n");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_list_size(begin));
	t_list *temp = begin->next;
	free(begin->data);
	free(begin);
	begin = temp;
	printf("	\x1b[34m[2]\x1b[36m \x1b 1,2,3,4,5,6,7,8,10 && free begin once\x1b[0m\n");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_list_size(begin));
	int count;

	printf("	\x1b[34m[3]\x1b[36m \x1b How many lists do you want to delete? :  \x1b[0m");
	scanf("%d", &count);
	if (count > 9)
		count = 9;
	for (int i = 0 ;i < count ;i++)
	{
		temp = begin->next;
		free(begin->data);
		free(begin);
		begin = temp;
	}
	
	printf("	   \x1b[0m \x1b[36mlist : \x1b[0m");
	print_list(begin);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_list_size(begin));
	free_list(&begin);

}

void		test_ft_list_sort(void)
{
	printf("\x1b[32mft_list_sort:\x1b[0m\n");

	t_list *begin = NULL;
	ft_list_push_front(&begin, strdup("ant"));
	ft_list_push_front(&begin, strdup("good"));
	ft_list_push_front(&begin, strdup("pigeon"));
	ft_list_push_front(&begin, strdup("bee"));
	ft_list_push_front(&begin, strdup("penguin"));
	ft_list_push_front(&begin, strdup("zoo"));
	ft_list_push_front(&begin, strdup("panda"));

	printf("	\x1b[34m[1]\x1b[36m \x1b\x1b[0m");
	printf("	\x1b[33m<before>\x1b[0m  ");
	print_list(begin);
	ft_list_sort(&begin, &strcmp);
	printf("		\x1b[33m< after>\x1b[0m  ");
	print_list(begin);
}

void		test_ft_list_remove_if(void)
{
	printf("\x1b[32mft_list_remove_if:\x1b[0m\n");
	t_list *begin = NULL;
	ft_list_push_front(&begin, strdup("ant"));
	ft_list_push_front(&begin, strdup("bee"));
	ft_list_push_front(&begin, strdup("bee"));
	ft_list_push_front(&begin, NULL);
	ft_list_push_front(&begin, strdup("bear"));
	ft_list_push_front(&begin, strdup("ant"));

	printf("	\x1b[34m[1]\x1b[36m remove 'ant' \x1b\x1b[0m\n");
	printf("		\x1b[33m<before>\x1b[0m ");
	print_list(begin);
	ft_list_remove_if(&begin, "ant", &ft_strcmp, &free);
	printf("		\x1b[33m< after>\x1b[0m ");
	print_list(begin);
	printf("	\x1b[34m[2]\x1b[36m remove 'bee' \x1b\x1b[0m\n");
	printf("		\x1b[33m<before>\x1b[0m ");
	print_list(begin);
	ft_list_remove_if(&begin, "bee", &ft_strcmp, &free);
	printf("		\x1b[33m< after>\x1b[0m ");
	print_list(begin);
	printf("	\x1b[34m[3]\x1b[36m remove 'bear' \x1b\x1b[0m\n");
	printf("		\x1b[33m<before>\x1b[0m ");
	print_list(begin);
	ft_list_remove_if(&begin, "bear", &ft_strcmp, &free);
	printf("		\x1b[33m< after>\x1b[0m ");
	print_list(begin);

	free_list(&begin);

}

int			main(int argc, char *argv[])
{
	if (argc == 1 || !strcmp(argv[1], "ft_strlen"))
		test_ft_strlen();
	if (argc == 1 || !strcmp(argv[1], "ft_strcpy"))
		test_ft_strcpy();
	if (argc == 1 || !strcmp(argv[1], "ft_strcmp"))
		test_ft_strcmp();
	if (argc == 1 || !strcmp(argv[1], "ft_write"))
		test_ft_write();
	if (argc == 1 || !strcmp(argv[1], "ft_read"))
		test_ft_read();
	if (argc == 1 || !strcmp(argv[1], "ft_strdup"))
		test_ft_strdup();
	if (argc == 1 || !strcmp(argv[1], "ft_atoi_base"))
		test_ft_atoi_base();
	if (argc == 1 || !strcmp(argv[1], "ft_list_push_front"))
		test_ft_list_push_front();
	if (argc == 1 || !strcmp(argv[1], "ft_list_size"))
		test_ft_list_size();
	if (argc == 1 || !strcmp(argv[1], "ft_list_sort"))
		test_ft_list_sort();
	if (argc == 1 || !strcmp(argv[1], "ft_list_remove_if"))
		test_ft_list_remove_if();
}
