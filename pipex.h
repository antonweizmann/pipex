/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:20:05 by antonweizma       #+#    #+#             */
/*   Updated: 2024/01/23 13:49:01 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/include/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

void	free_array(char **arr);
char	*get_path(char *cmd, char **envp);
void	error_msg(char *err);
int		msg(char *err);
#endif
