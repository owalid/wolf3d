/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:18:51 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/07 17:45:19 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp_node;

	tmp_node = *alst;
	while (tmp_node)
	{
		*alst = (*alst)->next;
		ft_lstdelone(&tmp_node, del);
		tmp_node = *alst;
	}
}
