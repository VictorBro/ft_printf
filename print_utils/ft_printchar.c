/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:59:50 by vbronov           #+#    #+#             */
/*   Updated: 2024/10/19 18:10:13 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_char(char c, t_opt *opt)
{
	int	n;

	if (opt->error)
		return (0);
	n = write(1, &c, 1);
	if (n != 1)
	{
		opt->error = 1;
		return (0);
	}
	return (1);
}

int	ft_printchar(char c, t_opt *opt)
{
	int	cur;

	cur = 0;
	while (!opt->error && cur + 1 < opt->min_width)
		cur += print_char(' ', opt);
	if (!opt->error)
		cur += print_char(c, opt);
	while (!opt->error && cur < opt->padding)
		cur += print_char(' ', opt);
	return (cur);
}
