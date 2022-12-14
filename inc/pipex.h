/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:25:29 by lwee              #+#    #+#             */
/*   Updated: 2022/10/24 16:37:03 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "get_next_line.h"
# include "libft.h"

/*  utils.c  */
void	free_strs(char *str, char **strs);
char	*get_env_path(char **envp);
char	**get_env_paths(char **envp);
char	*get_cmd_path(char *cmd, char **paths);

#endif
