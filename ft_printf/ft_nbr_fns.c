/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_fns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 06:13:30 by lwee              #+#    #+#             */
/*   Updated: 2022/06/18 07:40:51 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlenll(long long nb)
{
	int	n;

	n = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb *= -1;
	while (nb)
	{
		nb /= 10;
		n++;
	}
	return (n);
}

void	ft_putnbrll(long long nb)
{
	if (nb < 0)
		nb *= -1;
	if (nb > 9)
		ft_putnbrll(nb / 10);
	ft_putchar_fd(nb % 10 + '0', 1);
}
