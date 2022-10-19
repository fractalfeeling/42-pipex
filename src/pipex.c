/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:15:56 by lwee              #+#    #+#             */
/*   Updated: 2022/10/19 22:08:09 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	exec_process(char *argv, char **envp, char **paths)
{
	char	**cmd_options;
	char	*cmd_path;

	cmd_options = ft_split(argv, ' ');
	cmd_path = get_cmd_path(cmd_options[0], paths);
	if (cmd_path == NULL)
	{
		free_strs(NULL, cmd_options);
		exit(0);
	}
	if (execve(cmd_path, cmd_options, envp) == -1)
		exit(0);
}

void	create_child(char *argv, char **envp, char **paths)
{
	pid_t	pid;
	int		fd_pipe[2];

	if (pipe(fd_pipe) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		close(fd_pipe[0]);
		dup2(fd_pipe[1], STDOUT_FILENO);
		exec_process(argv, envp, paths);
	}
	else if (pid > 0)
	{
		close(fd_pipe[1]);
		dup2(fd_pipe[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	init_here_doc(char *limiter)
{
	int		fd_tmp;
	int		fd_stdin;
	char	*line;

	fd_tmp = open(".here_doc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_tmp == -1)
		exit(1);
	fd_stdin = dup(STDIN_FILENO);
	line = "";
	while (1)
	{
		ft_putstr_fd("here_doc > ", 1);
		line = get_next_line(fd_stdin);
		if (line == NULL)
			exit(1);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			break ;
		else
			ft_putstr_fd(line, fd_tmp);
		free_strs(line, NULL);
	}
	free_strs(line, NULL);
	close(fd_tmp);
	close(fd_stdin);
}

int	handle_iofiles(int argc, char **argv, int *fd_infile, int *fd_outfile)
{
	int	here_doc;

	here_doc = -1;
	if (argc >= 5 && ft_strncmp(argv[1], "here_doc", 8) != 0)
	{
		here_doc = 0;
		*fd_outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		*fd_infile = open(argv[1], O_RDONLY, 0644);
		dup2(*fd_infile, STDIN_FILENO);
	}
	else if (argc >= 6 && ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		here_doc = 1;
		*fd_outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		init_here_doc(argv[2]);
		*fd_infile = open(".here_doc.tmp", O_RDONLY);
		dup2(*fd_infile, STDIN_FILENO);
	}
	if (here_doc == -1 || *fd_outfile == -1 || *fd_infile == -1)
		exit(1);
	return (here_doc);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		fd_infile;
	int		fd_outfile;
	int		here_doc;
	int		i;

	if (argc < 5)
		exit(1);
	paths = get_env_paths(envp);
	if (paths == NULL)
		return (0);
	here_doc = handle_iofiles(argc, argv, &fd_infile, &fd_outfile);
	i = 2 + here_doc;
	while (i < argc - 2)
		create_child(argv[i++], envp, paths);
	if (here_doc == 1)
		unlink(".here_doc.tmp");
	dup2(fd_outfile, STDOUT_FILENO);
	exec_process(argv[i], envp, paths);
}
