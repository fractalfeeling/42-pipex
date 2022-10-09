/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:03:21 by lwee              #+#    #+#             */
/*   Updated: 2022/10/09 16:12:18 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	pid_t	pid;
	int		ends[2];
	char	secret[30];
	int		reader;
	char	buffer[30];

	if (pipe(ends) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		close(ends[0]);
		printf("Child: I'm writing my secret in the pipe...\n");
		strcpy(secret, "I am your child, mwahaha!");
		write(ends[1], secret, strlen(secret));
		close(ends[1]);
		return (0);
	}
	else
	{
		close(ends[1]);
		waitpid(pid, NULL, 0);
		printf("Parent: I received my child. What is its secret?\n");
		reader = read(ends[0], buffer, 30);
		close(ends[0]);
		if (reader == -1)
			return (3);
		buffer[reader] = '\0';
		printf("Parent: Oh boy! The secret is: \"%s\"\n", buffer);
	}
}
