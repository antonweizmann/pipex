/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:27:38 by antonweizma       #+#    #+#             */
/*   Updated: 2024/01/17 11:25:08 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **envp)
{
	char *cmd_path;
	char **cmd_arg;

	cmd_arg = ft_split(cmd, ' ');
	cmd_path = get_path(cmd_arg[0], envp);
	if (!cmd_arg || !cmd_path)
		// error();
	execve(cmd_path, cmd_arg, NULL);
		perror("Error");
	free(cmd_path);
	free_array(cmd_arg);

}

void	parent(char **argv, int *fd_pipe, char **envp)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT);
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

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(0);
	dup2(fd, STDIN_FILENO);
	dup2(fd_pipe[1], STDOUT_FILENO);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	close(fd);
	exec(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd_pipe[2];
	pid_t	pid;

	ft_printf("%s\n", argv[1]);
	if (argc != 5)
		exit(-1);
	if (pipe(fd_pipe) == -1)
		exit(-1);
	pid = fork();

	if (pid < 0)
		exit(-1);
	if (pid == 0)
		child(argv, fd_pipe, envp);
	else
		parent(argv, fd_pipe, envp);
	// waitpid(pid, NULL, 0);
	// close(fd_pipe[0]);
	// close(fd_pipe[1]);
	return (0);
}
