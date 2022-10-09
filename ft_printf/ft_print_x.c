/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:46:50 by lwee              #+#    #+#             */
/*   Updated: 2022/06/20 14:45:57 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static char	*ft_uitoa_hex(unsigned int n, char x)
{
	char			*str;
	int				len;
	unsigned long	nb;

	len = ft_hexlen(n);
	nb = n;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nb)
	{
		if (nb % 16 > 9)
			str[len] = nb % 16 - 10 + x - 23;
		else
			str[len] = nb % 16 + '0';
		len--;
		nb = nb / 16;
	}
	return (str);
}

static void	x_handle_width(t_format *format, int len)
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

static void	handle_x(t_format *format, char *str, int len, int diff)
{
	if (format->point == 1)
		format->flag[e_zero] = '0';
	if (format->flag[e_zero] == '1' && format->flag[e_hash] == '1')
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(*format->fstring, 1);
	}
	if (format->flag[e_minus] != '1')
		x_handle_width(format, len);
	if (format->flag[e_zero] != '1' && format->flag[e_hash] == '1')
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(*format->fstring, 1);
	}
	while (diff-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	if (format->flag[e_minus] == '1')
		x_handle_width(format, len);
}

void	ft_print_x(t_format *format)
{
	char			*str;
	unsigned int	nb;
	int				len;
	int				diff;

	nb = va_arg(format->arguments, unsigned int);
	str = ft_uitoa_hex(nb, *format->fstring);
	len = ft_strlen(str);
	if (nb == 0 && format->point == 1 && format->precision == 0)
	{
		len = 0;
		*str = '\0';
	}
	diff = format->precision - len;
	if (diff < 0)
		diff = 0;
	if (nb == 0)
		format->flag[e_hash] = '0';
	if (format->flag[e_hash] == '1')
		len += 2;
	len += diff;
	handle_x(format, str, len, diff);
	format->total += len;
	format->fstring++;
	free(str);
}
