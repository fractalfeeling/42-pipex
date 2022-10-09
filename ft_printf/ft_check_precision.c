/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:36:28 by lwee              #+#    #+#             */
/*   Updated: 2022/06/15 20:34:26 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_precision(t_format *format)
{
	format->point = 0;
	format->precision = 0;
	if (*format->fstring == '.')
	{
		format->point = 1;
		format->fstring++;
		if (*format->fstring >= '0' && *format->fstring <= '9')
			format->precision = ft_atoi(format->fstring);
		while (*format->fstring >= '0' && *format->fstring <= '9')
			format->fstring++;
		if (*format->fstring == '*')
		{
			format->precision = va_arg(format->arguments, int);
			if (format->precision < 0)
			{
				format->point = 0;
				format->precision = 0;
			}
			format->fstring++;
		}
	}
}
