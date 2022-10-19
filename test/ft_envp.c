/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:56:03 by lwee              #+#    #+#             */
/*   Updated: 2022/10/09 01:30:28 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_strs(char *str, char **strs)
{
	int	i;

	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	if (strs != NULL)
	{
		i = 0;
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
		strs = NULL;
	}
}

char	*get_env_path(char **envp)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (envp[i] && envp[i][0])
	{
		path = ft_strnstr(envp[i], "PATH=", 5);
		if (path)
		{
			path = ft_substr(path, 5, ft_strlen(path) - 5);
			break;
		}
		i++;
	}
	return (path);
}


static char	**get_env_paths(char **envp)
{
	char	*tmp;
	char	**paths;
	int		i;

	tmp = get_env_path(envp);
	if (tmp == NULL)
		return (NULL);
	paths = ft_split(tmp, ':');
	free_strs(tmp, NULL);
	if (paths == NULL)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free_strs(tmp, NULL);
		i++;
	}
	return (paths);
}

static char	*get_cmd_path(char *cmd, char **paths)
{
	char	*cmd_path;
	int		i;

	cmd_path = NULL;
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (cmd_path == NULL)
		{
			free_strs(NULL, paths);
		}
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free_strs(cmd_path, NULL);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	char	**paths;
	int		i;
	char	*cmd_path;
	char	*cmd="ls";

	paths = get_env_paths(envp);
	i = 0;
	while (paths[i])
	{
		ft_printf("%s\n", paths[i]);
		i++;
	}
	cmd_path = get_cmd_path(cmd, paths);
	ft_printf("%s\n", cmd_path);
}
