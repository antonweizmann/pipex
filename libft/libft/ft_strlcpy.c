/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:39:56 by aweizman          #+#    #+#             */
/*   Updated: 2023/10/11 14:34:01 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = 0;
	while (srclen + 1 < dstsize && *src)
	{
		*dst++ = *src++;
		srclen++;
	}
	if (srclen < dstsize)
		*dst = '\0';
	while (*src++)
		srclen++;
	return (srclen);
}
