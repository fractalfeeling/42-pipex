/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:29:57 by lwee              #+#    #+#             */
/*   Updated: 2022/10/09 15:31:49 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid > 0)
	{
		printf("Parent: I'm the parent, my child's pid is %d.\n", pid);
		while (1)
			usleep(1);
	}
	else if (pid == 0)
	{
		printf("Child: I'm the child, my internal pid is %d.\n", pid);
		printf("Child: Done!\n");
	}
	return (0);
}
