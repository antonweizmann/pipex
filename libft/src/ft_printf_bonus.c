/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:12:25 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/15 16:10:02 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

static void	check_cond2(const char *str, t_printf *cond, int i)
{
	if (str[i] == 'c')
		ft_getchar((unsigned char)(va_arg(cond->arg, int)), cond);
	if (str[i] == 's')
		ft_getstr(va_arg(cond->arg, char *), cond);
	if (str[i] == 'd' || str[i] == 'i')
		ft_getnbr((long)va_arg(cond->arg, int), cond, 0);
	if (str[i] == 'p')
		ft_getptr((unsigned long)va_arg(cond->arg, void *), cond, 1);
	if (str[i] == 'u')
		ft_getnbr((long)va_arg(cond->arg, unsigned int), cond, 0);
	if (str[i] == 'x' )
		ft_getnbr((long)va_arg(cond->arg, unsigned int), cond, 1);
	if (str[i] == 'X')
		ft_getnbr((long)va_arg(cond->arg, unsigned int), cond, 2);
	if (str[i] == '%')
		ft_getchar('%', cond);
}

static int	check_cond1(const char *str, t_printf *cond)
{
	int	i;

	i = 1;
	cond->plus = 0;
	cond->space = 0;
	cond->hash = 0;
	cond->error = 0;
	while (!ft_strchr("cspdiuxX%", str[i]))
	{
		if (str[i] == ' ')
			cond->space = 1;
		if (str[i] == '+')
			cond->plus = 1;
		if (str[i] == '#')
			cond->hash = 1;
		i++;
	}
	check_cond2(str, cond, i);
	return (i);
}

static void	writeprintf(const char *str, t_printf *cond)
{
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			cond->len++;
		}
		else
			str += check_cond1(str, cond);
		str++;
	}
	return ;
}

int	ft_printf(const char *str, ...)
{
	t_printf	cond;
	int			len;

	cond.len = 0;
	va_start(cond.arg, str);
	writeprintf(str, &cond);
	if (cond.error == -1)
	{
		va_end(cond.arg);
		return (-1);
	}
	len = cond.len;
	va_end(cond.arg);
	return (len);
}
