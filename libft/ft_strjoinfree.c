/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:27:48 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/08 10:00:13 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char *s1, char *s2, size_t l, int opt)
{
	char	*ptr;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = (char*)ft_strnew(sizeof(char) * len)))
		return (NULL);
	ft_strcpy(ptr, s1);
	ft_strncat(ptr, s2, l);
	(opt == 1) ? ft_strdel(&s1) : 0;
	(opt == 2) ? ft_strdel(&s2) : 0;
	if (opt == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (ptr);
}
