/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:45:34 by lwee              #+#    #+#             */
/*   Updated: 2022/10/09 22:19:41 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;

	if (ac < 5)
	{
		if (!ft_strncmp("here_doc", argv[1], 9))
			ft_printf("Usage: ./pipex here_doc LIMITER cmd cmd1 file");
		else
			ft_printf("Usage: ./pipex file1 cmd1 cmd2 ... cmdn file2");
		return (1);
	}
	else if (ac < 6 && !ft_strncmp("here_doc", argv[1], 9))
	{
		ft_printf("Usage: ./pipex here_doc LIMITER cmd cmd1 file");
		return (1);
	}
	if (!envp || !envp[0][0])
	{
		ft_printf("Unexpected error with environment path.");
		return (1);
	}
	return (0);
}
