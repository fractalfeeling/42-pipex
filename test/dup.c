/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:19:20 by lwee              #+#    #+#             */
/*   Updated: 2022/10/09 16:23:27 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	int		fd;
	int		fd_copy;
	int		reader;
	char	buffer[15];

	printf("My PID is %d\n", getpid());
	fd = open("test.txt", O_RDONLY);
	if (!fd)
		return (1);
	fd_copy = dup(fd);
	if (!fd_copy)
		return (1);
	reader = read(fd, buffer, 10);
	if (reader == -1)
		return (1);
	buffer[reader] = '\0';
	printf("fd %d contains: %s\n", fd, buffer);
	reader = read(fd_copy, buffer, 10);
	if (reader == -1)
		return (1);
	printf("fd %d contains: %s\n", fd_copy, buffer);
	while (1)
		;
}
