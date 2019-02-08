/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:43:31 by gdrai             #+#    #+#             */
/*   Updated: 2019/02/06 17:02:34 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	deal_mouse_calcul(int x, t_mlx *mlx)
{
	mlx->infos->wolf->hit = 0;
	mlx->infos->wolf->map_x = (int)mlx->infos->wolf->pos_x;
	mlx->infos->wolf->map_y = (int)mlx->infos->wolf->pos_y;
	mlx->infos->wolf->i_coord = 2 * (x / (double)WIDTH) - 1;
	mlx->infos->wolf->dir_ray_x = mlx->infos->wolf->dir_x
		+ mlx->infos->wolf->plane_x * mlx->infos->wolf->i_coord;
	mlx->infos->wolf->dir_ray_y = mlx->infos->wolf->dir_y
		+ mlx->infos->wolf->plane_y * mlx->infos->wolf->i_coord;
	mlx->infos->wolf->delta_x = fabs(1 / mlx->infos->wolf->dir_ray_x);
	mlx->infos->wolf->delta_y = fabs(1 / mlx->infos->wolf->dir_ray_y);
	pos_to_map(mlx);
	wait_for_hit(mlx);
}

int		deal_mouse(int mouse, int x, int y, t_mlx *mlx)
{
	(void)y;
	if (mouse == 1)
	{
		deal_mouse_calcul(x, mlx);
		if (mlx->infos->wolf->map[(int)mlx->infos->
			wolf->map_x][(int)mlx->infos->wolf->map_y] == 9)
		{
			if ((int)mlx->infos->wolf->map_x && (int)mlx->infos->wolf->map_y
				&& (int)mlx->infos->wolf->map_y != mlx->infos->wolf->map_width
					- 1 && (int)mlx->infos->wolf->map_x
						!= mlx->infos->wolf->map_height - 1)
				mlx->infos->wolf->map[(int)mlx->infos->
					wolf->map_x][(int)mlx->infos->wolf->map_y] = 0;
			else
				mlx->infos->wolf->map[(int)mlx->infos->
					wolf->map_x][(int)mlx->infos->wolf->map_y] = 1;
		}
		else
			mlx->infos->wolf->map[(int)mlx->infos->
				wolf->map_x][(int)mlx->infos->wolf->map_y]++;
	}
	return (0);
}
