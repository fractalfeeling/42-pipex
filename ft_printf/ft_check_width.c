/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 03:57:24 by lwee              #+#    #+#             */
/*   Updated: 2022/06/06 13:46:31 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_width(t_format *format)
{
	format->width = 0;
	if (*format->fstring >= '0' && *format->fstring <= '9')
		format->width = ft_atoi(format->fstring);
	while (*format->fstring >= '0' && *format->fstring <= '9')
		format->fstring++;
	if (*format->fstring == '*')
	{
		format->width = va_arg(format->arguments, int);
		if (format->width < 0)
		{
			format->flag[e_minus] = '1';
			format->width = -1 * format->width;
		}
		format->fstring++;
	}
}
