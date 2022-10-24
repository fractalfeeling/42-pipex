/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:58:58 by lwee              #+#    #+#             */
/*   Updated: 2022/10/24 14:46:15 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define FD_SIZE 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

// GNL
void	free_str(char **str);
int		find_newline(char *str);
void	read_line(int fd, char **storage);
char	*get_line(char **storage);
char	*get_next_line(int fd);

#endif
