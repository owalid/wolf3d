/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:26:00 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/07 17:43:22 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;

	if (!(ptr = (char*)malloc(sizeof(*s) * (ft_strlen(s) + 1))))
		return (NULL);
	return (ft_strcpy(ptr, s));
}
