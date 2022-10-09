/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:46:50 by lwee              #+#    #+#             */
/*   Updated: 2022/06/20 15:18:15 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_uintlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char			*str;
	int				len;
	unsigned long	nb;

	len = ft_uintlen(n);
	nb = n;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nb)
	{
		str[len] = nb % 10 + 48;
		len--;
		nb = nb / 10;
	}
	return (str);
}

static void	u_handle_width(t_format *format, int len)
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

static void	handle_u(t_format *format, char *str, int len, int diff)
{
	if (format->point == 1)
		format->flag[e_zero] = '0';
	if (format->flag[e_minus] != '1')
		u_handle_width(format, len);
	while (diff-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	if (format->flag[e_minus] == '1')
		u_handle_width(format, len);
}

void	ft_print_u(t_format *format)
{
	char			*str;
	unsigned int	nb;
	int				len;
	int				diff;

	nb = va_arg(format->arguments, unsigned int);
	str = ft_uitoa(nb);
	len = ft_strlen(str);
	if (nb == 0 && format->point == 1 && format->precision == 0)
	{
		len = 0;
		*str = '\0';
	}
	diff = format->precision - len;
	if (diff < 0)
		diff = 0;
	len += diff;
	handle_u(format, str, len, diff);
	format->total += len;
	format->fstring++;
	free(str);
}
