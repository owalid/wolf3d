/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:26:18 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/02/11 15:04:09 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_supdigit_at(int nb, int rank)
{
	nb -= ft_pow(get_digit_at(nb, rank), rank);
	return (nb);
}
