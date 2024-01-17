/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:55:30 by aweizman          #+#    #+#             */
/*   Updated: 2023/10/10 13:07:04 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		end;

	end = 0;
	while (str[end])
		end++;
	while (end >= 0)
	{
		if (str[end] == (char)c)
			return ((char *)str + end);
		end--;
	}
	return (0);
}
