/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:52:00 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/13 19:17:09 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strlowcase(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (ft_isupper(str[i]))
			str[i] += 32;
	return (str);
}