/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:43:14 by exam              #+#    #+#             */
/*   Updated: 2019/01/03 10:39:18 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, int b)
{
	char	*ptr;
	long	nb;
	int		i;

	i = (value < 0 && b == 10) ? 2 : 1;
	nb = (value < 0) ? -(long)value : value;
	while (nb /= b)
		++i;
	if (!(ptr = (char*)malloc(i + 1)))
		return (NULL);
	nb = (value < 0) ? -(long)value : value;
	ptr[i] = '\0';
	while (nb)
	{
		ptr[--i] = (nb % b < 10) ? (nb % b + '0') : (nb % b - 10 + 'A');
		nb /= b;
	}
	if (i)
		ptr[0] = '-';
	return (ptr);
}
