/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 23:59:48 by glavigno          #+#    #+#             */
/*   Updated: 2018/08/17 11:54:54 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *current;

	current = *begin_list;
	if (!*begin_list)
		*begin_list = ft_create_elem(data);
	else
	{
		while (current->next)
			current = current->next;
		current->next = ft_create_elem(data);
	}
}
