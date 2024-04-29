/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:08:50 by aweizman          #+#    #+#             */
/*   Updated: 2024/04/29 14:09:22 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*get_next_line(int fd);

char	*ft_strjoin(const char *s1, const char *s2);

size_t	ft_strlen(const char *str);

void	ft_bzero(void *str, size_t len);

char	*ft_strdup(const char *s1);

char	*ft_strchr(const char *str, int c);

void	*ft_calloc(size_t count, size_t size);

#endif
