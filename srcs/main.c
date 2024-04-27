/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:27:38 by antonweizma       #+#    #+#             */
/*   Updated: 2024/04/27 20:11:10 by antonweizma      ###   ########.fr       */
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

void	exec(char *cmd, t_args *args)
{
	char		*cmd_path;
	char		**cmd_arg;
	extern char	**environ;

	cmd_arg = ft_split(cmd, ' ');
	cmd_path = get_path(cmd_arg[0], environ);
	if (!cmd_path)
		free_array(cmd_arg);
	execve(cmd_path, cmd_arg, environ);
	perror("Command not found\n");
	free(cmd_arg);
	free(cmd_path);
	free(args);
	exit(1);
}

void	here_doc(t_args *args)
{
	char	*str;

	if (pipe(args->here_doc_pipe) == -1)
		perror("Pipe");
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (str && *str)
		{
			if (!ft_strncmp(str, args->argv[2], ft_strlen(args->argv[2]))
				&& !ft_strncmp(str, args->argv[2], ft_strlen(str) - 1))
			{
				free(str);
				break ;
			}
			write(args->here_doc_pipe[1], str, ft_strlen(str));
			free(str);
		}
	}
	close(args->here_doc_pipe[1]);
}

void	init_args(t_args *args, char **argv, int argc)
{
	args->argv = argv;
	args->argc = argc;
	if (!ft_strncmp(argv[1], "here_doc", 9))
		args->here_doc = 1;
	else
		args->here_doc = 0;
}

int	main(int argc, char **argv)
{
	t_args	*args;

	if (argc > 4)
	{
		args = malloc(sizeof(t_args));
		if (!args)
			return (msg("Args allocation failed\n"));
		init_args(args, argv, argc);
		if (args->here_doc)
		{
			if (argc < 6)
				error_msg("here_doc: Wrong Number of Arguments", args);
			here_doc(args);
		}
		start_pipe(NULL, args, 1);
	}
	else
		return (msg("Invalid Number of Arguments\n"));
	return (0);
}
