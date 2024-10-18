/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:20:40 by vbronov           #+#    #+#             */
/*   Updated: 2024/10/18 23:35:11 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	handle_number(unsigned int n, t_opt opt, int isupper, int padding)
{
	int	total;

	total = 0;
	if (!opt.minus && (!opt.zero || opt.dot))
		total += print_padding(padding, ' ');
	if (opt.sharp && n != 0)
	{
		if (isupper)
			total += print_str("0X");
		else
			total += print_str("0x");
	}
	if (opt.zero && !opt.dot && !opt.minus)
		total += print_padding(padding, '0');
	if (opt.dot)
		total += print_padding(opt.dot_width - count_digits(n, 16), '0');
	if (isupper)
		total += print_digits(n, "0123456789ABCDEF", 16);
	else
		total += print_digits(n, "0123456789abcdef", 16);
	if (opt.minus)
		total += print_padding(opt.min_width - total, ' ');
	return (total);
}

int	ft_printhex(unsigned int n, t_opt opt, int isupper)
{
	int	len;
	int	padding;

	opt.min_width = ft_max(opt.min_width, opt.dot_width);
	opt.min_width = ft_max(opt.min_width, opt.zero_width);
	opt.min_width = ft_max(opt.min_width, opt.padding);
	if (n == 0 && opt.dot && opt.dot_width == 0)
		return (print_padding(opt.min_width, ' '));
	len = ft_max(opt.dot_width, count_digits(n, 16));
	padding = opt.min_width - len;
	if (opt.sharp && n != 0)
		padding -= 2;
	if (opt.minus)
		opt.zero = 0;
	return (handle_number(n, opt, isupper, padding));
}