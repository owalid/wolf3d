/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:19:19 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/18 14:14:27 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp_node;
	t_list	*begin_node;

	if (lst && f)
	{
		if (!(tmp_node = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		lst = lst->next;
		tmp_node = f(tmp_node);
		begin_node = tmp_node;
		while (lst)
		{
			tmp_node->next = f(ft_lstnew(lst->content, lst->content_size));
			if (!tmp_node->next)
				return (NULL);
			tmp_node = tmp_node->next;
			lst = lst->next;
		}
		return (begin_node);
	}
	return (NULL);
}
