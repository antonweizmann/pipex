/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:20:05 by antonweizma       #+#    #+#             */
/*   Updated: 2024/04/27 20:18:04 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_args
{
	char	**argv;
	int		argc;
	int		here_doc;
	int		here_doc_pipe[2];
}	t_args;

void	start_pipe(int *pre_fd, t_args *args, int commands);
void	free_array(char **arr);
char	*get_path(char *cmd, char **envp);
void	error_msg(char *err, t_args *args);
int		msg(char *err);
void	exec(char *cmd, t_args *args);
void	fork_tree(int *pre_fd, t_args *args, int commands, int *status);
void	parent(t_args *args, int *fd, int *pre_fd);
void	child(t_args *args, int *fd, int *pre_fd, int cmd);
void	initiate_child(t_args *args, int *pre_fd, int *fd);
void	close_pipes(int *fd);
#endif
