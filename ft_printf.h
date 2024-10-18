/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:14:46 by vbronov           #+#    #+#             */
/*   Updated: 2024/10/18 23:38:46 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# ifndef PRINTF_NULL_PTR
#  if defined(__linux__)
#   define PRINTF_NULL_PTR	"(nil)"
#  elif defined(__APPLE__)
#   define PRINTF_NULL_PTR	"0x0"
#  else
#   define PRINTF_NULL_PTR	"0x0"
#  endif
# endif

typedef struct s_opt
{
	int	sharp;
	int	space;
	int	plus;
	int	min_width;
	int	minus;
	int	dot;
	int	dot_width;
	int	padding;
	int	zero;
	int	zero_width;
}		t_opt;

int		ft_printf(const char *str, ...);

int		ft_printchar(char c, t_opt opt);
int		ft_printstr(char *str, t_opt opt);
int		ft_printptr(void *ptr, t_opt opt);
int		ft_printnum(int n, t_opt opt);
int		ft_printunum(unsigned int n, t_opt opt);
int		ft_printhex(unsigned int n, t_opt opt, int isupper);

int		print_str(char *str);
int		print_char(char c);
int		ft_max(int a, int b);
void	init_opt(t_opt *opt);
int		count_digits(unsigned int n, int base);
int		print_padding(int count, char pad_char);
int		print_digits(unsigned int n, char *base, unsigned int base_len);
#endif
