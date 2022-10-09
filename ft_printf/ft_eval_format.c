/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 03:09:35 by lwee              #+#    #+#             */
/*   Updated: 2022/06/06 13:46:51 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_eval_format(t_format *format)
{
	format->fstring++;
	ft_check_flags(format);
	ft_check_width(format);
	ft_check_precision(format);
	ft_check_specifier(format);
}
