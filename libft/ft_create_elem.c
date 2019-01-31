/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 23:45:18 by glavigno          #+#    #+#             */
/*   Updated: 2018/08/18 16:12:54 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*node;

	if (!(node = malloc(sizeof(t_list))))
		return (NULL);
	node->content = data;
	node->next = NULL;
	return (node);
}
