/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:32:27 by lwee              #+#    #+#             */
/*   Updated: 2022/06/06 11:35:09 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fstring, ...)
{
	t_format	*format;
	int			length;

	format = ft_calloc(1, sizeof(t_format));
	va_start(format->arguments, fstring);
	format->fstring = fstring;
	while (*format->fstring)
	{
		while (*format->fstring && *format->fstring != '%')
		{
			ft_putchar_fd(*format->fstring, 1);
			format->fstring++;
			format->total++;
		}
		if (*format->fstring == '%')
			ft_eval_format(format);
	}
	va_end(format->arguments);
	length = format->total;
	free (format);
	return (length);
}
