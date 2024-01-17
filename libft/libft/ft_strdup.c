/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:09:55 by aweizman          #+#    #+#             */
/*   Updated: 2023/10/12 11:25:01 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*temp;

	dup = (char *)malloc(sizeof(*s1) * (1 + ft_strlen(s1)));
	if (!dup)
		return (NULL);
	temp = dup;
	while (*s1)
		*dup++ = *s1++;
	*dup = '\0';
	return (temp);
}
