/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:18:30 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/08 08:48:59 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ptr;
	int		length;
	int		nb;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb = (n < 0) ? -n : n;
	length = nb;
	i = (n < 0) ? 2 : 1;
	while (length /= 10)
		++i;
	if (!(ptr = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		ptr[i] = nb % 10 + '0';
		nb /= 10;
	}
	if (i && n < 0)
		ptr[0] = '-';
	return (ptr);
}
