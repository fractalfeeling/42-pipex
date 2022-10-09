/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:25:29 by lwee              #+#    #+#             */
/*   Updated: 2022/10/09 18:11:49 by lwee             ###   ########.fr       */
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
# include "ft_printf.h"

/*  parse_env.c  */
char	*get_env_path(char **envp);
char	**get_env_paths(char **envp);
char	*get_cmd_path(char *cmd, char **paths);

/*  utils.c  */
void	free_strs(char *str, char **strs);

#endif
