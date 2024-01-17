/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:28:53 by aweizman          #+#    #+#             */
/*   Updated: 2024/01/17 13:56:50 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_sort
{
	int				size;
	struct s_stack	*max;
	struct s_stack	*min;
}	t_sort;

typedef struct s_stack
{
	int				content;
	int				index;
	int				cost;
	bool			over_midpoint;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

int		ft_toupper(int c);

int		ft_tolower(int c);

char	*ft_substr(const char *s, unsigned int start, size_t len);

char	*ft_strtrim(const char *s1, const char *set);

int		ft_strcmp(const char *str1, const char *str2);

char	*ft_strrchr(const char *str, int c);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int		ft_strncmp(const char *str1, const char *str2, size_t n);

size_t	ft_strlen(const char *str);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_strdup(const char *s1);

char	*ft_strchr(const char *str, int c);

char	**ft_split(const char *s, char c);

void	*ft_memset(void *str, int c, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memcpy(void *dst, const void *src, size_t len);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_isprint(int c);

int		ft_isdigit(int c);

int		ft_isascii(int c);

int		ft_isalpha(int c);

int		ft_isalnum(int c);

char	*ft_itoa(int n);

void	*ft_calloc(size_t count, size_t size);

void	ft_bzero(void *str, size_t len);

int		ft_atoi(const char *str);

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putchar_fd(char c, int fd);

void	ft_putnbr_fd(int n, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putstr_fd(char *s, int fd);

t_stack	*ft_lstnew(int content);

void	ft_lstadd_front(t_stack **lst, t_stack *new);

int		ft_lstsize(t_stack *lst);

t_stack	*ft_lstlast(t_stack *lst);

void	ft_lstadd_back(t_stack **lst, t_stack *new);

void	ft_lstdelone(t_stack *lst);

void	ft_lstclear(t_stack **lst);

void	ft_lstiter(t_stack *lst, void (*f)(int));

#endif
