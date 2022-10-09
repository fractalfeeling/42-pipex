/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:57:46 by lwee              #+#    #+#             */
/*   Updated: 2022/06/20 13:58:19 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	s_handle_width(t_format *format, int len)
{
	while (format->width > len)
	{
		ft_putchar_fd(' ', 1);
		format->width--;
		format->total++;
	}
}

static void	handle_s(t_format *format, char *str, int len)
{
	if (format->flag[e_minus] == '1')
		ft_putstr_fd(str, 1);
	s_handle_width(format, len);
	if (format->flag[e_minus] != '1')
		ft_putstr_fd(str, 1);
}

void	ft_print_s(t_format *format)
{
	char	*str;
	char	*tmp;
	int		len;

	tmp = va_arg(format->arguments, char *);
	str = tmp;
	if (tmp == NULL)
		tmp = "(null)";
	if (format->point == 0)
		str = ft_strdup(tmp);
	else if (format->point == 1)
	{
		if (!IS_MACOS && (format->precision > 0 && format->precision < 6)
			&& (ft_strncmp(tmp, "(null)", 6) == 0))
			format->precision = 0;
		str = ft_substr(tmp, 0, format->precision);
	}
	len = ft_strlen(str);
	handle_s(format, str, len);
	format->total += len;
	format->fstring++;
	free(str);
}
