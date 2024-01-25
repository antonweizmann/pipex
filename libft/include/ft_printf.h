/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:12:14 by aweizman          #+#    #+#             */
/*   Updated: 2024/01/25 14:43:04 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct s_printf
{
	va_list		arg;
	int			plus;
	int			space;
	int			hash;
	int			len;
	int			error;
}	t_printf;

void		ft_getnbr(long long nb, t_printf *cond, int i);

void		ft_getstr(char *str, t_printf *cond);

int			ft_printf(const char *str, ...);

void		ft_getchar(unsigned char c, t_printf *cond);

void		ft_getptr(unsigned long nb, t_printf *cond, int i);

#endif
