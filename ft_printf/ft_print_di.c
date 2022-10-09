/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:46:50 by lwee              #+#    #+#             */
/*   Updated: 2022/06/18 08:37:22 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	di_handle_sign(t_format *format, int nb)
{
	if (nb < 0)
		ft_putchar_fd('-', 1);
	if (format->flag[e_space] == '1' && nb >= 0)
		ft_putchar_fd(' ', 1);
	if (format->flag[e_plus] == '1' && nb >= 0)
		ft_putchar_fd('+', 1);
}

static void	di_handle_width(t_format *format, int len)
{
	while (format->width > len)
	{
		if (format->flag[e_zero] == '1')
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		format->width--;
		format->total++;
	}
}

static void	di_handle_minus(t_format *format, int nb, int len, int diff)
{
	di_handle_sign(format, nb);
	while (diff-- > 0)
		ft_putchar_fd('0', 1);
	if (!(nb == 0 && format->point == 1 && format->precision == 0))
		ft_putnbrll(nb);
	di_handle_width(format, len);
}

static void	di_handle_all(t_format *format, int nb, int len, int diff)
{
	if (format->flag[e_zero] == '0')
		di_handle_width(format, len);
	di_handle_sign(format, nb);
	if (format->flag[e_zero] == '1')
		di_handle_width(format, len);
	while (diff-- > 0)
		ft_putchar_fd('0', 1);
	if (!(nb == 0 && format->point == 1 && format->precision == 0))
		ft_putnbrll(nb);
}

void	ft_print_di(t_format *format)
{
	long long	nb;
	int			len;
	int			diff;

	nb = (int)va_arg(format->arguments, long long);
	len = ft_nbrlenll(nb);
	diff = format->precision - len;
	if (diff < 0)
		diff = 0;
	len += diff;
	if (nb == 0 && format->point == 1 && format->precision == 0)
		len = 0;
	if (format->flag[e_space] == '1' && nb >= 0)
		len++;
	if (format->flag[e_plus] == '1' || nb < 0)
		len++;
	if (format->point == 1)
		format->flag[e_zero] = '0';
	if (format->flag[e_minus] == '1')
		di_handle_minus(format, nb, len, diff);
	else
		di_handle_all(format, nb, len, diff);
	format->total += len;
	format->fstring++;
}
