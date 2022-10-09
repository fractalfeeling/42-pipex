/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 03:30:23 by lwee              #+#    #+#             */
/*   Updated: 2022/06/06 13:45:42 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flags(t_format *format)
{
	format->flag[e_hash] = '0';
	format->flag[e_zero] = '0';
	format->flag[e_minus] = '0';
	format->flag[e_space] = '0';
	format->flag[e_plus] = '0';
	while (*format->fstring == '#' || *format->fstring == '0'
		|| *format->fstring == '-' || *format->fstring == ' '
		|| *format->fstring == '+')
	{
		if (*format->fstring == '#')
			format->flag[e_hash] = '1';
		if (*format->fstring == '0')
			format->flag[e_zero] = '1';
		if (*format->fstring == '-')
			format->flag[e_minus] = '1';
		if (*format->fstring == ' ')
			format->flag[e_space] = '1';
		if (*format->fstring == '+')
			format->flag[e_plus] = '1';
		format->fstring++;
	}
	if (format->flag[e_zero] == '1' && format->flag[e_minus] == '1')
		format->flag[e_zero] = '0';
	if (format->flag[e_space] == '1' && format->flag[e_plus] == '1')
		format->flag[e_space] = '0';
}
