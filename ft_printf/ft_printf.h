/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 19:43:55 by jikwon            #+#    #+#             */
/*   Updated: 2020/05/09 14:52:49 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define DEC "0123456789"
# define HEX_L "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"

typedef struct	s_option
{
	int	bar;
	int	zero;
	int	min_width;
	int	prec;
	int sign;
}				t_option;

void			init_tlist(t_option **flag);
int				ft_atoi_l(const char *str, int *i);
void			check_width(const char *str, int *i,
		va_list args, t_option **flag);
void			check_prec(const char *str, int *i,
		va_list args, t_option **flag);
void			set_flag(const char *str, int *i,
		va_list args, t_option **flag);
void			ft_putstr(char *s, int len, int *cnt);
char			*ft_jst_str(char *s, int count_w, t_option *flag);
char			*ft_jst_int(char *s, int count_w, t_option *flag);
char			*ft_setprec(t_option *flag, char *s);
char			*ft_setzero(t_option *flag, char *s, int sign);

void			print_c(int *cnt, unsigned char temp, t_option *flag);
void			print_s(int *cnt, char *temp, t_option *flag);
void			print_p(int *cnt, void *temp, t_option *flag);
void			print_di(int *cnt, int temp, t_option *flag);
void			print_ux(int *cnt, unsigned int temp,
		t_option *flag, char *base);
void			print_conv(const char *str, int *i, int *cnt, va_list args);
int				ft_printf(const char *str, ...);
#endif
