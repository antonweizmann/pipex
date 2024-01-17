/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:39:49 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/15 16:09:47 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	apply_conds(long long nb, t_printf *cond, int up)
{
	if (cond->hash && up > 0 && nb > 0)
	{
		if (up == 1)
		{
			ft_putstr_fd("0x", 1);
			cond->len += 2;
		}
		if (up == 2)
		{
			ft_putstr_fd("0X", 1);
			cond->len += 2;
		}
	}
	if (cond->plus && nb >= 0)
	{
		ft_putchar_fd('+', 1);
		cond->len++;
	}
	else if (cond->space && nb >= 0)
	{
		ft_putchar_fd(' ', 1);
		cond->len++;
	}
	return (0);
}

static int	ft_addnbr(long long nb, int i, int base, t_printf *cond)
{
	if (nb < 0)
	{
		nb *= -1;
		cond->len++;
		ft_putchar_fd('-', 1);
	}
	if (nb > base - 1)
	{
		ft_addnbr(nb / base, i, base, cond);
		ft_addnbr(nb % base, i, base, cond);
	}
	else
	{
		if (nb < 10)
			ft_putchar_fd(nb + '0', 1);
		else
		{
			if (i == 1)
				ft_putchar_fd(nb - 10 + 'a', 1);
			else
				ft_putchar_fd(nb - 10 + 'A', 1);
		}
		cond->len++;
	}
	return (0);
}

void	ft_getnbr(long long nb, t_printf *cond, int i)
{
	int	base;

	base = 10;
	if (i > 0)
		base = 16;
	apply_conds(nb, cond, i);
	if (nb == 0)
		cond->len += write(1, "0", 1);
	else
		ft_addnbr(nb, i, base, cond);
	return ;
}

static int	ft_addptr(unsigned long nb, int i, t_printf *cond)
{
	if (nb > 15)
	{
		ft_addptr(nb / 16, i, cond);
		ft_addptr(nb % 16, i, cond);
	}
	else
	{
		if (nb < 10)
			ft_putchar_fd(nb + '0', 1);
		else
		{
			if (i == 1)
				ft_putchar_fd(nb - 10 + 'a', 1);
			else
				ft_putchar_fd(nb - 10 + 'A', 1);
		}
		cond->len++;
	}
	return (0);
}

void	ft_getptr(unsigned long nb, t_printf *cond, int i)
{
	cond->len += write(1, "0x", 2);
	if (nb == 0)
		cond->len += write(1, "0", 1);
	else
		ft_addptr(nb, i, cond);
	return ;
}
