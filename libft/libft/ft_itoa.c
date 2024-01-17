/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:37:13 by antonweizma       #+#    #+#             */
/*   Updated: 2023/10/11 14:29:17 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	if (n < 0)
	{
		i++;
		nb = -n;
	}
	else
		nb = n;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			digit_count;
	unsigned int	nb;

	digit_count = count_digits(n);
	str = malloc(sizeof(char) * (digit_count + 1));
	if (!str)
		return (NULL);
	str[digit_count] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	while (nb > 9)
	{
		str[--digit_count] = nb % 10 + 48;
		nb /= 10;
	}
	str[--digit_count] = nb % 10 + 48;
	return (str);
}
