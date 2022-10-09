/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:18:11 by lwee              #+#    #+#             */
/*   Updated: 2022/06/20 15:08:05 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_specifier(t_format *format)
{
	if (*format->fstring == 'c')
		ft_print_c(format);
	else if (*format->fstring == 's')
		ft_print_s(format);
	else if (*format->fstring == 'p')
		ft_print_p(format);
	else if (*format->fstring == 'd' || *format->fstring == 'i')
		ft_print_di(format);
	else if (*format->fstring == 'u')
		ft_print_u(format);
	else if (*format->fstring == 'x' || *format->fstring == 'X')
		ft_print_x(format);
	else if (*format->fstring == '%')
		ft_print_pct(format);
}
