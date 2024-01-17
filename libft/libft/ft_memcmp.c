/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:38 by aweizman          #+#    #+#             */
/*   Updated: 2023/10/11 14:29:57 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	int					diff;
	size_t				i;

	str1 = s1;
	str2 = s2;
	i = 0;
	diff = 0;
	while (!diff && i++ < n)
		diff = *str1++ - *str2++;
	if (!diff && i++ < n)
		diff = *str1++ - *str2++;
	return (diff);
}
