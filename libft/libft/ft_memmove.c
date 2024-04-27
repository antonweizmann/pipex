/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:01:59 by aweizman          #+#    #+#             */
/*   Updated: 2024/04/27 20:17:38 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*temp1;
	const unsigned char	*temp2;
	const void			*src_end;
	void				*dst_end;

	if ((!dst && !src) || len == 0)
		return (dst);
	src_end = src + len - 1;
	dst_end = dst + len - 1;
	temp1 = dst;
	temp2 = src;
	if (dst >= src && dst <= src_end)
	{
		temp1 = dst_end;
		temp2 = src_end;
		while (len-- > 0)
			*temp1-- = *temp2--;
		return (dst);
	}
	while (len-- > 0)
		*temp1++ = *temp2++;
	return (dst);
}
