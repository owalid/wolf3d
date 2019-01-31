/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:32:05 by glavigno          #+#    #+#             */
/*   Updated: 2019/01/03 10:23:55 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*begin;
	char	*end;
	char	*ptr;

	if (!s)
		return (NULL);
	while (is_whitespace(*s))
		++s;
	if (!*s)
	{
		if (!(ptr = (char*)malloc(sizeof(char))))
			return (NULL);
		ft_bzero(ptr, 1);
		return (ptr);
	}
	begin = (char*)s;
	while (*(s + 1))
		++s;
	while (is_whitespace(*s))
		--s;
	end = (char*)s;
	if (!(ptr = ft_strnew(end - begin + 1)))
		return (NULL);
	return (ft_strncpy(ptr, begin, end - begin + 1));
}
