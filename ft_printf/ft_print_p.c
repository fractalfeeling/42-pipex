/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:28:31 by lwee              #+#    #+#             */
/*   Updated: 2022/06/20 14:50:49 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	p_itoa_hex(size_t nb)
{
	if (nb > 15)
	{
		p_itoa_hex(nb / 16);
		p_itoa_hex(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd(nb + '0', 1);
		else
			ft_putchar_fd(nb - 10 + 'a', 1);
	}
}

static void	p_handle_width(t_format *format, int addrlen)
{
	while (format->width > addrlen)
	{
		ft_putchar_fd(' ', 1);
		format->width--;
		format->total++;
	}
}

static void	handle_p(t_format *format, unsigned long long addr, int addrlen,
	int diff)
{
	if (format->flag[e_minus] != '1')
		p_handle_width(format, addrlen);
	if (addr == 0 && IS_MACOS)
		ft_putstr_fd("0x0", 1);
	else if (addr == 0)
		ft_putstr_fd("(nil)", 1);
	else
	{
		ft_putstr_fd("0x", 1);
		while (diff > 0)
		{
			ft_putchar_fd('0', 1);
			diff--;
		}
		p_itoa_hex(addr);
	}
	if (format->flag[e_minus] == '1')
		p_handle_width(format, addrlen);
}

void	ft_print_p(t_format *format)
{
	size_t	addr;
	size_t	tmp;
	int		addrlen;
	int		diff;

	addr = (size_t)va_arg(format->arguments, void *);
	tmp = addr;
	addrlen = 2;
	while (tmp > 0)
	{
		tmp /= 16;
		addrlen++;
	}
	diff = format->precision - addrlen + 2;
	if (diff < 0)
		diff = 0;
	if (addr == 0 && IS_MACOS)
		addrlen += 1;
	else if (addr == 0)
		addrlen += 3;
	addrlen = diff + addrlen;
	handle_p(format, addr, addrlen, diff);
	format->total = format->total + addrlen;
	format->fstring++;
}
