/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:19:40 by antonweizma       #+#    #+#             */
/*   Updated: 2024/01/17 10:40:33 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env(char **envp)
{
	int	i;
	int	j;
	char *tmp;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		tmp = ft_substr(envp[i], 0, j);
		// if (!tmp)
		// 	error();
		if (ft_strcmp(tmp, "PATH") == 0)
		{
			free(tmp);
			return (envp[i] + j + 1);
		}
		free(tmp);
		i++;
	}
	return(NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	**cmd_path;
	char	*path_to_cmd;
	char	*trial_path;
	int		i;

	cmd_path = ft_split(get_env(envp), ':');
	path_to_cmd = ft_strjoin("/", cmd);
	// if (!cmd_path || !path_to_cmd)
	// 	error();
	i = 0;
	while (cmd_path[i])
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
	return (NULL);
}
void	free_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);

}