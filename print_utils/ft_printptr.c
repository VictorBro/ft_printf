/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:02:37 by vbronov           #+#    #+#             */
/*   Updated: 2024/10/18 23:57:36 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_hex(unsigned long addr, char *base)
{
	int	total;

	total = 0;
	if (addr < 16)
	{
		total += print_char(base[addr]);
		return (total);
	}
	total += print_hex(addr / 16, base);
	total += print_char(base[addr % 16]);
	return (total);
}

static int	get_hex_size(unsigned long addr)
{
	int	total;

	total = 0;
	if (addr == 0)
		return (1);
	while (addr > 0)
	{
		addr /= 16;
		total++;
	}
	return (total);
}

int	ft_printptr(void *ptr, t_opt opt)
{
	unsigned long	addr;
	int				total;
	int				len;

	addr = (unsigned long)ptr;
	total = 0;
	if (addr == 0)
		len = ft_strlen(PRINTF_NULL_PTR);
	else
		len = get_hex_size(addr) + 2;
	while (len + total < opt.min_width)
		total += print_char(' ');
	if (addr == 0)
		total += print_str(PRINTF_NULL_PTR);
	else
	{
		total += print_str("0x");
		total += print_hex(addr, "0123456789abcdef");
	}
	while (total < opt.padding)
		total += print_char(' ');
	return (total);
}
