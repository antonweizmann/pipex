/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:15:13 by aweizman          #+#    #+#             */
/*   Updated: 2024/04/23 10:26:55 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initiate_child(t_args *args, int *pre_fd)
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
	close(pre_fd[0]);
	dup2(pre_fd[1], STDOUT_FILENO);
	close(pre_fd[1]);
	exec(args->argv[2 + args->here_doc]);
}

void	child(t_args *args, int *fd, int *pre_fd, int cmd)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(pre_fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(pre_fd[0]);
	close(pre_fd[1]);
	exec(args->argv[args->argc - 1 - cmd]);
}

void	parent(t_args *args, int *fd)
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
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(file);
	exec(args->argv[args->argc - 2]);
}

void	start_pipe(int *pre_fd, t_args *args, int commands)
{
	int	status;

	status = 0;
	fork_tree(pre_fd, args, commands, &status);
	free(args);
	exit(status);
}

void	fork_tree(int *pre_fd, t_args *args, int commands, int *status)
{
	int		fd[2];
	int		pid;

	pid = fork();
	if (pid == -1)
		perror("Fork");
	if (commands < args->argc - 3 - args->here_doc)
	{
		if (pipe(fd) == -1)
			perror("Pipe");
		if (pid)
			fork_tree(fd, args, commands + 1, status);
		else if (!pid && commands == 1)
			parent(args, fd);
		else if (!pid)
			child(args, fd, pre_fd, commands);
	}
	else if (commands == args->argc - 3 - args->here_doc)
	{
		if (!pid)
			initiate_child(args, pre_fd);
	}
	waitpid(pid, status, 0);
}
