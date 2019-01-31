/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:27:57 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/05 18:27:58 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	t;
	size_t	u;

	t = ft_strlen(dest);
	if (n < t)
		return (ft_strlen(src) + n);
	u = 0;
	while (t < (n - 1) && src[u])
		dest[t++] = src[u++];
	dest[t] = '\0';
	while (src[u++])
		++t;
	return (t);
}
