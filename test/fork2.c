/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:12:17 by lwee              #+#    #+#             */
/*   Updated: 2022/10/09 15:21:04 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		printf("Child: I'm the child, my internal pid is %d.\n", pid);
		usleep(1000000);
		printf("Child: Done!\n");
	}
	else if (pid > 0)
	{
		printf("Parent: I'm the parent, my child's pid is %d.\n", pid);
		printf("Parent: Done!\n");
	}
	return (0);
}
