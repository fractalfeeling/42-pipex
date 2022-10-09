/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:55:33 by lwee              #+#    #+#             */
/*   Updated: 2022/06/06 13:59:46 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	c_handle_width(t_format *format)
{
	while (format->width > 1)
	{
		ft_putchar_fd(' ', 1);
		format->width--;
		format->total++;
	}
}

void	ft_print_c(t_format *format)
{
	char	c;

	c = va_arg(format->arguments, int);
	if (format->flag[e_minus] == '1')
		ft_putchar_fd(c, 1);
	c_handle_width(format);
	if (format->flag[e_minus] != '1')
		ft_putchar_fd(c, 1);
	format->total++;
	format->fstring++;
}
