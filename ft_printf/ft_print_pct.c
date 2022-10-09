/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:55:33 by lwee              #+#    #+#             */
/*   Updated: 2022/07/11 18:49:00 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pct_handle_width(t_format *format)
{
	while (format->width > 1)
	{
		if (format->flag[e_zero] == '1')
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		format->width--;
		format->total++;
	}
}

void	ft_print_pct(t_format *format)
{
	if (format->flag[e_minus] == '1')
		ft_putchar_fd('%', 1);
	if (IS_MACOS)
		pct_handle_width(format);
	if (format->flag[e_minus] == '0')
		ft_putchar_fd('%', 1);
	format->total++;
	format->fstring++;
}
