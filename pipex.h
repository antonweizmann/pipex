/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:20:05 by antonweizma       #+#    #+#             */
/*   Updated: 2024/01/17 10:40:30 by antonweizma      ###   ########.fr       */
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
#endif
