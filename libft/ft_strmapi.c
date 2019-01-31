/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:28:28 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/08 10:01:32 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	t;

	t = 0;
	if (!s || !f)
		return (NULL);
	if (!(ptr = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[t])
	{
		ptr[t] = f(t, s[t]);
		++t;
	}
	return (ptr);
}
