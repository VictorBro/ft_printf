/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:02:49 by vbronov           #+#    #+#             */
/*   Updated: 2024/10/18 22:02:51 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_str(char *str)
{
	int	n;

	n = 0;
	while (str && *str)
		n += print_char(*str++);
	return (n);
}

static int	print_str_size(char *str, int size)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (str && str[i] && i < size)
		total += print_char(str[i++]);
	return (total);
}

int	ft_printstr(char *str, t_opt opt)
{
	int	len;
	int	total;

	if (!str && opt.dot && opt.dot_width < 6)
		len = 0;
	else
	{
		if (!str)
			str = "(null)";
		len = ft_strlen(str);
		if (opt.dot && opt.dot_width < len)
			len = opt.dot_width;
	}
	total = 0;
	if (opt.minus)
	{
		total += print_str_size(str, len);
		while (len++ < opt.padding)
			total += print_char(' ');
		return (total);
	}
	while (opt.min_width-- > len)
		total += print_char(' ');
	total += print_str_size(str, len);
	return (total);
}