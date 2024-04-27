/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:15:13 by aweizman          #+#    #+#             */
/*   Updated: 2024/04/27 17:32:42 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initiate_child(t_args *args, int *fd, int *pre_fd)
{
	int	file;

	file = 0;
	if (args->here_doc)
	{
		dup2(args->here_doc_pipe[0], STDIN_FILENO);
		close(args->here_doc_pipe[0]);
		close(args->here_doc_pipe[1]);
	}
	else
	{
		file = open(args->argv[1], O_RDONLY, 0666);
		if (file == -1)
		{
			perror("Infile");
			exit(EXIT_FAILURE);
		}
		dup2(file, STDIN_FILENO);
		close(file);
	}
	dup2(fd[1], STDOUT_FILENO);
	close_pipes(pre_fd);
	close_pipes(fd);
	exec(args->argv[2 + args->here_doc]);
}

void	child(t_args *args, int *pre_fd, int *fd, int cmd)
{
	dup2(pre_fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close_pipes(pre_fd);
	close_pipes(fd);
	exec(args->argv[args->argc - 1 - cmd]);
}

void	parent(t_args *args, int *pre_fd, int *fd)
{
	int	file;

	if (args->here_doc)
		file = open(args->argv[args->argc - 1],
				O_WRONLY | O_APPEND | O_CREAT, 0666);
	else
		file = open(args->argv[args->argc - 1],
				O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (file == -1)
	{
		perror("Outfile");
		exit(EXIT_FAILURE);
	}
	dup2(pre_fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close_pipes(fd);
	close_pipes(pre_fd);
	close(file);
	exec(args->argv[args->argc - 2]);
}

void	start_pipe(int *pre_fd, t_args *args, int commands)
{
	int	status;

	status = 0;
	fork_tree(pre_fd, args, commands, &status);
	free(args);
	// ft_putnbr_fd(status, 2);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	exit(status);
}

void	fork_tree(int *pre_fd, t_args *args, int commands, int *status)
{
	int		fd[2];
	int		pid;

	if (pipe(fd) == -1)
		perror("Pipe");
	pid = fork();
	if (pid == -1)
		perror("Fork");
	if (!pid && commands < args->argc - 3 - args->here_doc)
	{
		if (commands == 1)
			initiate_child(args, fd, pre_fd);
		else
			child(args, pre_fd, fd, commands);
	}
	else if (pid && commands < args->argc - 3 - args->here_doc)
	{
		close_pipes(pre_fd);
		fork_tree(fd, args, commands + 1, status);
	}
	else if (!pid && commands == args->argc - 3 - args->here_doc)
		parent(args, pre_fd, fd);
	close_pipes(pre_fd);
	close_pipes(fd);
	waitpid(pid, status, 0);
}
