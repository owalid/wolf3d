/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:17:39 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/02/06 17:08:44 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_init(t_infoswind *infos)
{
	infos->wolf->pos_x = 1.5;
	infos->wolf->pos_y = 1.5;
	infos->wolf->dir_x = -1;
	infos->wolf->dir_y = 0;
	infos->wolf->plane_x = 0;
	infos->wolf->plane_y = 0.66;
}
