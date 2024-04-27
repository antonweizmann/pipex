/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:07:17 by aweizman          #+#    #+#             */
/*   Updated: 2024/04/27 20:19:22 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	char	*temp;
	size_t	i;

	i = size * count;
	mem = malloc(size * count);
	if (mem == NULL)
		return (NULL);
	temp = mem;
	while (i-- > 0)
		*temp++ = '\0';
	return (mem);
}

void	ft_bzero(void *str, size_t len)
{
	unsigned char	*temp;

	temp = str;
	while (len-- > 0)
		*temp++ = '\0';
}
