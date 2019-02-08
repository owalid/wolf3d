/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:41:21 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/02/06 17:08:52 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		wolf_err(int id)
{
	if (id == 1)
		ft_putendl_fd(ERR_MAP, 2);
	else if (id == 2)
		ft_putendl_fd(ERR_MLX, 2);
	else if (id == 3)
		ft_putendl_fd(ERR_MALLOC, 2);
	else if (id == 4)
		ft_putendl_fd(ERR_USAGE, 2);
	else if (id == 5)
		ft_putendl_fd(ERR_OPCL, 2);
	exit(id);
}

void		wolf_exit(int id)
{
	if (id == 0)
		ft_putendl(EXIT);
	system("killall afplay");
	exit(id);
}
