/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 20:15:22 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/31 20:21:50 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			wolf_move_left(t_mlx *mlx)
{
	mlx->infos->wolf->previous_dir_x = mlx->infos->wolf->dir_x;
	mlx->infos->wolf->dir_x = mlx->infos->wolf->dir_x *
		cos(RO) - mlx->infos->wolf->dir_y * sin(RO);
	mlx->infos->wolf->dir_y = mlx->infos->wolf->previous_dir_x *
		sin(RO) + mlx->infos->wolf->dir_y * cos(RO);
	mlx->infos->wolf->prev_plane_x = mlx->infos->wolf->plane_x;
	mlx->infos->wolf->plane_x = mlx->infos->wolf->plane_x *
		cos(RO) - mlx->infos->wolf->plane_y * sin(RO);
	mlx->infos->wolf->plane_y = mlx->infos->wolf->prev_plane_x *
		sin(RO) + mlx->infos->wolf->plane_y * cos(RO);
}

void			wolf_move_right(t_mlx *mlx)
{
	mlx->infos->wolf->previous_dir_x = mlx->infos->wolf->dir_x;
	mlx->infos->wolf->dir_x = mlx->infos->wolf->dir_x *
		cosf(-RO) - mlx->infos->wolf->dir_y * sinf(-RO);
	mlx->infos->wolf->dir_y = mlx->infos->wolf->previous_dir_x *
		sinf(-RO) + mlx->infos->wolf->dir_y * cosf(-RO);
	mlx->infos->wolf->prev_plane_x = mlx->infos->wolf->plane_x;
	mlx->infos->wolf->plane_x = mlx->infos->wolf->plane_x *
		cosf(-RO) - mlx->infos->wolf->plane_y * sinf(-RO);
	mlx->infos->wolf->plane_y = mlx->infos->wolf->prev_plane_x *
		sinf(-RO) + mlx->infos->wolf->plane_y * cosf(-RO);
}

void			wolf_move_up(t_mlx *mlx)
{
	if (mlx->infos->wolf->map[(int)(mlx->infos->wolf->pos_x + MO
				* mlx->infos->wolf->dir_x)]
			[(int)mlx->infos->wolf->pos_y] == 0)
		mlx->infos->wolf->pos_x += MO * mlx->infos->wolf->dir_x;
	if (mlx->infos->wolf->map[(int)mlx->infos->wolf->pos_x]
			[(int)(mlx->infos->wolf->pos_y + MO
				* mlx->infos->wolf->dir_y)] == 0)
		mlx->infos->wolf->pos_y += MO * mlx->infos->wolf->dir_y;
}

void			wolf_move_down(t_mlx *mlx)
{
	if (mlx->infos->wolf->map[(int)(mlx->infos->wolf->pos_x - MO
				* mlx->infos->wolf->dir_x)]
			[(int)mlx->infos->wolf->pos_y] == 0)
		mlx->infos->wolf->pos_x -= MO * mlx->infos->wolf->dir_x;
	if (mlx->infos->wolf->map[(int)mlx->infos->wolf->pos_x]
			[(int)(mlx->infos->wolf->pos_y - MO
				* mlx->infos->wolf->dir_y)] == 0)
		mlx->infos->wolf->pos_y -= MO * mlx->infos->wolf->dir_y;
}
