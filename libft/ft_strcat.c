/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:24:09 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/05 18:24:11 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	t;
	size_t	u;

	t = ft_strlen(dest);
	u = 0;
	while (src[u])
		dest[t++] = src[u++];
	dest[t] = '\0';
	return (dest);
}
