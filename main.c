/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:27:38 by antonweizma       #+#    #+#             */
/*   Updated: 2024/01/23 14:56:55 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	exec(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**cmd_arg;

	cmd_arg = ft_split(cmd, ' ');
	cmd_path = get_path(cmd_arg[0], envp);
	if (execve(cmd_path, cmd_arg, envp) == -1)
	{
		free(cmd_path);
		free_array(cmd_arg);
		error_msg("Command not found\n");
	}
	free(cmd_path);
	free_array(cmd_arg);
}

void	parent(char **argv, int *fd_pipe, char **envp)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (fd == -1)
		error_msg("Outfile");
	dup2(fd_pipe[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	close(fd);
	exec(argv[3], envp);
}

void	child(char **argv, int *fd_pipe, char **envp)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0666);
	if (fd == -1)
		error_msg("Infile");
	dup2(fd, STDIN_FILENO);
	dup2(fd_pipe[1], STDOUT_FILENO);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	close(fd);
	exec(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_pipe[2];
	pid_t	pid;

	if (argc != 5)
		return (msg("Invalid Number of Arguments\n"));
	if (pipe(fd_pipe) == -1)
		error_msg("Pipe");
	pid = fork();
	if (pid < 0)
	{
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		exit(1);
	}
	if (pid == 0)
		child(argv, fd_pipe, envp);
	else
		parent(argv, fd_pipe, envp);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	return (0);
}
