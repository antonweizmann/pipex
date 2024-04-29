/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:19:40 by antonweizma       #+#    #+#             */
/*   Updated: 2024/04/29 13:57:51 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env(char **environ, char *var)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (environ[i])
	{
		j = 0;
		while (environ[i][j] && environ[i][j] != '=')
			j++;
		tmp = ft_substr(environ[i], 0, j);
		if (!tmp)
			break ;
		if (!ft_strncmp(tmp, var, ft_strlen(var))
			&& !ft_strncmp(tmp, var, ft_strlen(tmp)))
		{
			free(tmp);
			return (ft_strdup(environ[i] + j + 1));
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	**cmd_path;
	char	*path_to_cmd;
	char	*trial_path;
	char	*tmp;
	int		i;

	tmp = get_env(envp, "PATH");
	cmd_path = ft_split(tmp, ':');
	free(tmp);
	path_to_cmd = ft_strjoin("/", cmd);
	i = 0;
	while (cmd_path && path_to_cmd && cmd_path[i])
	{
		trial_path = ft_strjoin(cmd_path[i], path_to_cmd);
		if (access(trial_path, F_OK | X_OK) == 0)
		{
			free(path_to_cmd);
			free_array(cmd_path);
			return (trial_path);
		}
		free(trial_path);
		i++;
	}
	free_array(cmd_path);
	return (free(path_to_cmd), NULL);
}

void	error_msg(char *err, t_args *args)
{
	perror(err);
	free(args);
	exit(1);
}

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	close_pipes(int *fd)
{
	if (fd)
	{
		close(fd[0]);
		close(fd[1]);
	}
}
