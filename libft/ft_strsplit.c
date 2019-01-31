/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:31:36 by glavigno          #+#    #+#             */
/*   Updated: 2019/01/03 10:40:15 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_counter(char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str != c && (*(str + 1) == c || !*(str + 1)))
			++i;
		++str;
	}
	return (i);
}

static int	create_table(char **tab, char *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] && str[i] != c)
		{
			j = 0;
			while (str[i + j] && str[i + j] != c)
				++j;
			if (!(tab[k] = ft_strnew(j)))
				return (0);
			ft_strncpy(tab[k], &str[i], j);
			++k;
			i += j;
		}
		else
			++i;
	}
	tab[k] = NULL;
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**full_table;
	size_t	number_of_words;

	if (!s)
		return (NULL);
	number_of_words = words_counter((char*)s, c);
	if (!(full_table = (char**)malloc(sizeof(char*) * (number_of_words + 1))))
		return (NULL);
	if (!(create_table(full_table, (char*)s, c)))
		return (NULL);
	return (full_table);
}
