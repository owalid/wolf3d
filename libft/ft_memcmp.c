/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:20:08 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/07 17:44:22 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if ((*(unsigned char*)s1) != (*(unsigned char*)s2))
			return ((int)(*(unsigned char*)s1) - (int)(*(unsigned char*)s2));
		++s1;
		++s2;
	}
	return (0);
}
