/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:07:04 by glavigno          #+#    #+#             */
/*   Updated: 2018/08/08 00:38:41 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		empty;

	i = -1;
	empty = 0;
	while (str[++i])
	{
		(!empty && ft_ismin(str[i])) ? str[i] -= 32 : 0;
		(empty && ft_ismaj(str[i])) ? str[i] += 32 : 0;
		empty = (!ft_isalpha(str[i]) && !ft_isdigit(str[i])) ? 0 : 1;
	}
	return (str);
}
