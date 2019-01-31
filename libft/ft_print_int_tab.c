/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:33:08 by glavigno          #+#    #+#             */
/*   Updated: 2019/01/03 10:36:08 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_tab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i++]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
}
