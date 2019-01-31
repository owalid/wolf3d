/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:17:41 by glavigno          #+#    #+#             */
/*   Updated: 2019/01/03 10:27:31 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap_str(char **c, char **d)
{
	char	*e;

	e = *c;
	*c = *d;
	*d = e;
}

static void	ft_sort_str_table(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			swap_str(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			++i;
	}
}

void		ft_sort_wordtab(char **tab)
{
	ft_sort_str_table(tab, ft_tablen(tab));
}
