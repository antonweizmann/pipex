/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:07:17 by aweizman          #+#    #+#             */
/*   Updated: 2023/10/23 11:07:03 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	char	*temp;

	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	temp = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (temp);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (*str++)
		len++;
	return (len);
}

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
