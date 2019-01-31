/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 09:35:03 by glavigno          #+#    #+#             */
/*   Updated: 2019/01/03 10:26:42 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*add_link(t_list *list, void *data)
{
	t_list	*element;

	if (!(element = ft_create_elem(data)))
		return (NULL);
	element->content = data;
	element->next = list;
	return (element);
}

t_list			*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	int		i;

	list = NULL;
	if (!ac)
		return (list);
	i = 0;
	while (++i < ac)
		list = add_link(list, av[i]);
	return (list);
}
