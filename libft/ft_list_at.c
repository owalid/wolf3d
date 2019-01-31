/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 10:29:02 by glavigno          #+#    #+#             */
/*   Updated: 2019/01/03 10:10:28 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	u;

	u = 0;
	if (!begin_list)
		return (NULL);
	while (begin_list && u++ < nbr)
		begin_list = begin_list->next;
	return ((u == nbr) ? begin_list : NULL);
}
