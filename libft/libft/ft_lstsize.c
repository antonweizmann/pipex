/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:12:16 by aweizman          #+#    #+#             */
/*   Updated: 2023/12/08 11:30:41 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_stack *lst)
{
	int		i;

	i = 1;
	if (!lst)
		return ('\0');
	while (lst -> next)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}
