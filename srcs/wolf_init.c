/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:17:39 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/31 19:08:24 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_init(t_infoswind *infos)
{
	t_img		img[1];

	infos->wolf->pos_x = 2.5;
	infos->wolf->pos_y = 2.5;
	infos->wolf->dir_x = -1;
	infos->wolf->dir_y = 0;
	infos->wolf->plane_x = 0;
	infos->wolf->plane_y = 0.66;
	img->bperpix = 32;
	img->size_line = WIDTH * 4;
	img->endian = 0;
	infos->img = img;
}
