/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:59:50 by vbronov           #+#    #+#             */
/*   Updated: 2024/10/18 17:59:52 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_char(char c)
{
	int	n;

	n = write(1, &c, 1);
	if (n != 1)
		return (0);
	return (1);
}

int	ft_printchar(char c, t_opt opt)
{
	int	cur;

	cur = 0;
	while (cur + 1 < opt.min_width)
		cur += print_char(' ');
	cur += print_char(c);
	while (cur < opt.padding)
		cur += print_char(' ');
	return (cur);
}
