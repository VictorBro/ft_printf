/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:01:58 by vbronov           #+#    #+#             */
/*   Updated: 2024/10/18 23:49:57 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	handle_number_format(int n, t_opt opt, int num_digits, int padding)
{
	int	total;

	total = 0;
	if (!opt.minus && (!opt.zero || opt.dot))
		total += print_padding(padding, ' ');
	if (n < 0)
		total += print_char('-');
	else if (opt.plus)
		total += print_char('+');
	else if (opt.space)
		total += print_char(' ');
	if (opt.zero && !opt.dot && !opt.minus)
		total += print_padding(padding, '0');
	if (opt.dot)
		total += print_padding(opt.dot_width - num_digits, '0');
	if (n >= 0)
		total += print_digits(n, "0123456789", 10);
	else if (n == -2147483648)
		total += print_str("2147483648");
	else
		total += print_digits(-n, "0123456789", 10);
	if (opt.minus)
		total += print_padding(opt.min_width - total, ' ');
	return (total);
}

int	ft_printnum(int n, t_opt opt)
{
	int	num_digits;
	int	len;
	int	padding;

	opt.min_width = ft_max(opt.min_width, opt.dot_width);
	opt.min_width = ft_max(opt.min_width, opt.zero_width);
	opt.min_width = ft_max(opt.min_width, opt.padding);
	if (n == 0 && opt.dot && opt.dot_width == 0)
		return (print_padding(opt.min_width, ' '));
	if (n >= 0)
		num_digits = count_digits(n, 10);
	else if (n == -2147483648)
		num_digits = 10;
	else
		num_digits = count_digits(-n, 10);
	len = ft_max(num_digits, opt.dot_width);
	padding = opt.min_width - len;
	if (padding > 0 && (n < 0 || opt.plus || opt.space))
		padding--;
	if (opt.minus)
		opt.zero = 0;
	return (handle_number_format(n, opt, num_digits, padding));
}
