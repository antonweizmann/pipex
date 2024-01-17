/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:38 by aweizman          #+#    #+#             */
/*   Updated: 2023/10/11 14:34:23 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int					diff;
	const unsigned char	*s1;
	const unsigned char	*s2;
	size_t				i;

	s1 = (unsigned char *) str1;
	s2 = (unsigned char *) str2;
	i = 0;
	diff = 0;
	while (!diff && *s1 && *s2 && i++ < n)
		diff = *s1++ - *s2++;
	if (!diff && (*s1 || *s2) && i++ < n)
		diff = *s1++ - *s2++;
	return (diff);
}
