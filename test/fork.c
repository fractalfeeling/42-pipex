/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:15:15 by lwee              #+#    #+#             */
/*   Updated: 2022/10/09 15:11:42 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	pid_t	pid;

	printf("Fork here.\n");
	pid = fork();
	if (pid == -1)
		return (1);
	printf("Fork successful!\n");
	if (pid > 0)
		printf("Parent: I'm the parent, my child's pid is %i.\n", pid);
	else if (pid == 0)
		printf("Child: I'm the child, my internal pid is %i.\n", pid);
	return (0);
}
