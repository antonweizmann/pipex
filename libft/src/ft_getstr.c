/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:07:15 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/15 16:09:55 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_getstr(char *str, t_printf *cond)
{
	if (str == NULL)
	{
		cond->len += 6;
		ft_putstr_fd("(null)", 1);
		return ;
	}
	cond->len += ft_strlen(str);
	ft_putstr_fd(str, 1);
}

void	ft_getchar(unsigned char c, t_printf *cond)
{
	cond->len++;
	ft_putchar_fd(c, 1);
}
