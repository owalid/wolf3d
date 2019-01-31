/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:31:06 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/07 10:40:46 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	n_length;

	if (!n)
		return (NULL);
	if (!*needle)
		return ((char*)haystack);
	n_length = ft_strlen(needle);
	while (*haystack && n-- >= n_length)
	{
		if (!ft_strncmp(haystack, needle, n_length))
			return ((char*)haystack);
		++haystack;
	}
	return (NULL);
}
