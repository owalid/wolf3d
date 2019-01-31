/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:31:43 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/05 18:31:45 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	length;

	if (!*needle)
		return ((char*)haystack);
	length = ft_strlen(needle);
	while (*haystack)
	{
		if (!ft_strncmp(haystack, needle, length))
			return ((char*)haystack);
		++haystack;
	}
	return (NULL);
}
