/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:18:51 by antonweizma       #+#    #+#             */
/*   Updated: 2023/10/08 10:34:02 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char	**free_split(char **split)
// {
// 	int	i;

// 	i = 0;
// 	while (split[i])
// 		free (split[i++]);
// 	free (split);
// 	return (NULL);
// }

// static int	count_words(const char *s, char c)
// {
// 	int	word_count;
// 	int	i;

// 	i = 0;
// 	word_count = 0;
// 	while (*s)
// 	{
// 		i = 0;
// 		while (*s && *s == c)
// 			s++;
// 		while (*s && *s != c)
// 		{
// 			s++;
// 			i = 1;
// 		}
// 		if (i)
// 			word_count++;
// 	}
// 	return (word_count);
// }

// static size_t	word_end(const char *s, char c, size_t i)
// {
// 	while (s[i] && s[i] != c)
// 		i++;
// 	return (i);
// }

// static int	make_words(char **split, const char *s, char c)
// {
// 	size_t	j;
// 	size_t	word_len;

// 	j = 0;
// 	while (s[j])
// 	{
// 		if (s[j] != c)
// 		{
// 			word_len = word_end(s, c, j) - j;
// 			*split = ft_calloc(sizeof(char), word_len + 1);
// 			if (!*split)
// 				return (-1);
// 			*split = ft_memcpy(*split, s + j, word_len);
// 			split++;
// 			j = word_len + j - 1;
// 		}
// 		j++;
// 	}
// 	return (0);
// }

// char	**ft_split(const char *s, char c)
// {
// 	char	**split;
// 	int		word_count;

// 	word_count = count_words(s, c);
// 	split = ft_calloc(sizeof(char *), word_count + 1);
// 	if (!split)
// 		return (NULL);
// 	split[word_count] = NULL;
// 	if (make_words(split, s, c) == -1)
// 		return (free_split(split));
// 	return (split);
// }
char **split(char const *s, char c)
{
	static int	iteration = 0;
	int			lettercount;
	char		**split_words;

	lettercount = 0;
	while (*s == c && *s)
		s++;
	while (s[lettercount] != c && s[lettercount])
		lettercount++;
	if (lettercount > 0 && ++iteration)
	{
		split_words = ft_split(s + lettercount, c);
		if (iteration-- && !split_words)
			return (NULL);
		split_words[iteration] = ft_substr(s, 0, lettercount);
		lettercount = 1;
		if (!split_words[iteration])
			while (split_words[iteration + lettercount])
				free(split_words[iteration + lettercount++]);
		if (!split_words[iteration])
			return (free(split_words), NULL);
	}
	else
		split_words = ft_calloc((iteration + 1), sizeof(char *));
	return (split_words);
}

char	**ft_split(char const *s, char c)
{
	if (!*s || !s)
		return (NULL);
	return (split(s, c));
}
