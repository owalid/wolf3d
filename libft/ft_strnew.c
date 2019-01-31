/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:30:35 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/07 17:41:59 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	if (!(ptr = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ptr[size] = '\0';
	while (size--)
		ptr[size] = '\0';
	return (ptr);
}
