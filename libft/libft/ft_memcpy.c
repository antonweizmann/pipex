/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:39:50 by aweizman          #+#    #+#             */
/*   Updated: 2023/10/11 14:30:06 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*temp1;
	const unsigned char	*temp2;

	temp1 = dst;
	temp2 = src;
	if ((!dst && !src) || len == 0)
		return (dst);
	while (len-- > 0)
		*temp1++ = *temp2++;
	return (dst);
}
