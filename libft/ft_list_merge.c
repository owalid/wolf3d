/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 14:59:18 by glavigno          #+#    #+#             */
/*   Updated: 2018/08/20 08:48:34 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current_node;

	current_node = *begin_list1;
	if (!*begin_list1)
		*begin_list1 = begin_list2;
	else
	{
		while (current_node->next)
			current_node = current_node->next;
		current_node->next = begin_list2;
	}
}
