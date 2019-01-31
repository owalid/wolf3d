/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 08:00:41 by glavigno          #+#    #+#             */
/*   Updated: 2019/01/03 10:27:00 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	unsigned int	u;
	unsigned int	v;
	char			c;

	if (!str || !*str)
		return (str);
	u = (unsigned int)ft_strlen(str) - 1;
	v = 0;
	while (v < u)
	{
		c = str[v];
		str[v] = str[u];
		str[u] = c;
		++v;
		--u;
	}
	return (str);
}
