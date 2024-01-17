/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:55:50 by aweizman          #+#    #+#             */
/*   Updated: 2023/10/11 14:34:43 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charcheck(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	int		i;
	char	*trimstr;

	start = 0;
	i = 0;
	end = ft_strlen(s1);
	if (!*s1)
		return (ft_calloc(1, 1));
	while (s1[start] && ft_charcheck(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_charcheck(set, s1[end - 1]) && (start < end))
		end--;
	trimstr = malloc(end - start + 1);
	if (trimstr == NULL)
		return (NULL);
	while (start < end)
		trimstr[i++] = s1[start++];
	trimstr[i] = '\0';
	return (trimstr);
}
