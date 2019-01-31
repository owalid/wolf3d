/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:19:38 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/08 09:43:23 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int		i;

	i = 0;
	while (n--)
	{
		((char*)dest)[i] = ((const char*)src)[i];
		if (((char*)dest)[i] == (char)c)
			return (dest + i + 1);
		++i;
	}
	return (NULL);
}
