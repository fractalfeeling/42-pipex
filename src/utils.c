/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:52:45 by lwee              #+#    #+#             */
/*   Updated: 2022/10/19 01:58:14 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_strs(char *str, char **strs)
{
	int	i;

	if (str)
	{
		free(str);
		str = NULL;
	}
	if (strs)
	{
		i = 0;
		while (strs[i])
			free(strs[i++]);
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

char	**get_env_paths(char **envp)
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

char	*get_cmd_path(char *cmd, char **paths)
{
	char	*cmd_path;
	int		i;

	cmd_path = NULL;
	i = 0;
	while (paths[i])
	{
		if (ft_strncmp(cmd, paths[i], ft_strlen(paths[i])) == 0)
			cmd_path = cmd;
		else
			cmd_path = ft_strjoin(paths[i], cmd);
		if (cmd_path == NULL)
		{
			free_strs(NULL, paths);
			exit(1);
		}
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free_strs(cmd_path, NULL);
		i++;
	}
	return (NULL);
}

/*
int	main(int argc, char **argv, char **envp)
{
	char	*path;
	char	**paths;
	int		i;
	char	*cmd_path;
	char	*cmd="bash";

	paths = get_env_paths(envp);
	i = 0;
	while (paths[i])
	{
		ft_printf("%s\n", paths[i]);
		i++;
	}
	cmd_path = get_cmd_path(cmd, paths);
	printf("CMD PATH: %s\n", cmd_path);
	printf("%d\n", access(cmd_path, F_OK | X_OK));
}
*/
