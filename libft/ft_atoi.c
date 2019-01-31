/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:17:10 by glavigno          #+#    #+#             */
/*   Updated: 2019/01/03 10:09:32 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *nptr)
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
	return ((int)(total * sign));
}
