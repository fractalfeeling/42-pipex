/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:55:46 by lwee              #+#    #+#             */
/*   Updated: 2022/10/09 16:00:48 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	pid_t	pid1;
	pid_t	pid2;
	pid_t	res;
	int		status;

	pid1 = fork();
	if (pid1 == -1)
		return (1);
	if (pid1 == 0)
	{
		usleep(50000);
		printf("Child 1: I'm the first child!\n");
		return (0);
	}
	else if (pid1 > 0)
	{
		pid2 = fork();
		if (pid2 == -1)
			return (1);
		if (pid2 == 0)
		{
			usleep(49900);
			printf("Child 2: I'm the second child!\n");
			return (2);
		}
		else if (pid2 > 0)
		{
			printf("Parent: I have two children!\n");
			res = waitpid(pid1, &status, 0);
			printf("Parent: I received my first child %d\n", res);
			if (WIFEXITED(status))
				printf("Parent: It exited successfully, exit code %d\n", WEXITSTATUS(status));
			else
				printf("Parent: It was interrupted...\n");
			res = waitpid(pid2, &status, 0);
			printf("Parent: I received my second child %d\n", res);
			if (WIFEXITED(status))
				printf("Parent: It exited successfully, exit code %d\n", WEXITSTATUS(status));
			else
				printf("Parent: It was interrupted...\n");
		}
	}
	return (0);
}

