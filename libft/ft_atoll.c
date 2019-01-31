/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:01:23 by glavigno          #+#    #+#             */
/*   Updated: 2019/01/09 18:01:26 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoll(const char *nptr)
{
	long long	total;
	short		sign;

	while (ft_isspace(*nptr))
		++nptr;
	sign = (*nptr == '-') ? -1 : 1;
	(*nptr == '+' || *nptr == '-') ? ++nptr : 0;
	total = 0;
	while (ft_isdigit(*nptr))
		total = total * 10 + *nptr++ - '0';
	return (total * sign);
}
