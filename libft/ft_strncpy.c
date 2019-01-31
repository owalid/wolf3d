/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:30:09 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/07 08:11:27 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	t;

	t = 0;
	while (src[t] && t < n)
	{
		dest[t] = src[t];
		++t;
	}
	while (t < n)
		dest[t++] = '\0';
	return (dest);
}
