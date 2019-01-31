/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:19:57 by glavigno          #+#    #+#             */
/*   Updated: 2019/01/14 16:38:24 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, int size)
{
	int		count;
	int		len;
	char	*str;

	len = 0;
	count = 0;
	len = ft_strlen(s);
	str = (size < len) ? ft_strnew(size) : ft_strnew(len);
	while (s[count] && count < size)
	{
		str[count] = s[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
