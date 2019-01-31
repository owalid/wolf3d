/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:31:25 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/05 18:31:27 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t length;

	length = ft_strlen(s);
	if (!c)
		return (&((char*)s)[length]);
	while (length-- && s[length])
	{
		if (s[length] == (unsigned char)c)
			return (&((char*)s)[length]);
	}
	return (NULL);
}
