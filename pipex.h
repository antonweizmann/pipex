/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:20:05 by antonweizma       #+#    #+#             */
/*   Updated: 2024/01/25 15:46:41 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/include/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_args
{
	char	**argv;
	int		argc;
	int		here_doc;
	int		here_doc_pipe[2];
}	t_args;

void	free_array(char **arr);
char	*get_path(char *cmd, char **envp);
void	error_msg(char *err, t_args *args);
int		msg(char *err);
void	exec(char *cmd, t_args *args);
void	fork_tree(int *pre_fd, t_args *args, int commands);
void	parent(t_args *args, int *fd);
void	child(t_args *args, int *fd, int *pre_fd, int cmd);
void	initiate_child(t_args *args, int *pre_fd);
#endif
