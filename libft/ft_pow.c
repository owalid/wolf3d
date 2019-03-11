/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:20:18 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/02/11 15:03:37 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long		ft_pow(int nb, int power)
{
	unsigned long long		result;

	result = nb;
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
