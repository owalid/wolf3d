/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 10:48:45 by glavigno          #+#    #+#             */
/*   Updated: 2019/01/09 17:59:31 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atol(const char *nptr)
{
	long	total;
	short	sign;

	while (ft_isspace(*nptr))
		++nptr;
	sign = (*nptr == '-') ? -1 : 1;
	(*nptr == '+' || *nptr == '-') ? ++nptr : 0;
	total = 0;
	while (ft_isdigit(*nptr))
		total = total * 10 + *nptr++ - '0';
	return (total * sign);
}
