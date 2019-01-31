/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:28:19 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/08 10:00:59 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	size_t	t;

	if (!s || !f)
		return (NULL);
	t = ft_strlen(s);
	if (!(ptr = ft_strnew(t)))
		return (NULL);
	while (t--)
		ptr[t] = f(s[t]);
	return (ptr);
}
