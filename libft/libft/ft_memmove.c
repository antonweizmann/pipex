/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:01:59 by aweizman          #+#    #+#             */
/*   Updated: 2023/10/11 14:30:16 by aweizman         ###   ########.fr       */
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
	src_end = &src[len - 1];
	dst_end = &dst[len - 1];
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
