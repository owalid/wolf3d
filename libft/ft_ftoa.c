/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:20:54 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/02/11 15:02:16 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				get_spart(int nb, int size, int power)
{
	unsigned long long		tmp;

	while (size)
	{
		tmp = (get_digit_at(nb, power - 1) * ft_pow(10, power - 2));
		nb -= tmp;
		power--;
		size--;
	}
	return (nb);
}

char			*ft_ftoa(float f)
{
	int		second_part;
	int		power_part;
	char	*strfir_part;
	char	*strsec_part;
	char	*result;

	power_part = (int)(f * ft_pow(10, 6));
	second_part = get_spart(power_part,
			get_size_nb((int)f), get_size_nb(power_part));
	second_part = ft_supzero(second_part);
	result = ft_strnew(get_size_nb((int)f) + get_size_nb(second_part) + 1);
	strfir_part = ft_strnew(get_size_nb((int)f) + 1);
	strfir_part = ft_itoa((int)f);
	strfir_part[get_size_nb((int)f)] = ',';
	strsec_part = ft_itoa(second_part);
	result = ft_strjoin(strfir_part, strsec_part);
	return (result);
}
