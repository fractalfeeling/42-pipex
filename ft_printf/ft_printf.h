/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:32:21 by lwee              #+#    #+#             */
/*   Updated: 2022/09/01 01:26:52 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include "../libft/libft.h"

# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif

enum	e_flags
{
	e_hash,
	e_zero,
	e_minus,
	e_space,
	e_plus,
};

typedef struct s_format
{
	const char	*fstring;
	va_list		arguments;
	char		flag[5];
	int			width;
	int			precision;
	int			point;
	int			total;
}	t_format;

int		ft_printf(const char *fstring, ...);

void	ft_eval_format(t_format *format);
void	ft_check_flags(t_format *format);
void	ft_check_width(t_format *format);
void	ft_check_precision(t_format *format);
void	ft_check_specifier(t_format *format);
void	ft_print_c(t_format *format);
void	ft_print_s(t_format *format);
void	ft_print_p(t_format *format);
void	ft_print_di(t_format *format);
void	ft_print_u(t_format *format);
void	ft_print_x(t_format *format);
void	ft_print_pct(t_format *format);

void	ft_putnbrll(long long nb);
int		ft_nbrlenll(long long nb);

#endif
