/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:11:08 by gdrai             #+#    #+#             */
/*   Updated: 2019/01/31 18:37:04 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		deal_key2(int key, t_mlx *mlx)
{
	if (key == DOWN_KEY)
	{
		if (mlx->infos->wolf->map[(int)(mlx->infos->wolf->pos_x - MO * mlx->infos->wolf->dir_x)][(int)mlx->infos->wolf->pos_y] == 0)
			mlx->infos->wolf->pos_x -= MO * mlx->infos->wolf->dir_x;
		if (mlx->infos->wolf->map[(int)mlx->infos->wolf->pos_x][(int)(mlx->infos->wolf->pos_y - MO * mlx->infos->wolf->dir_y)] == 0)
			mlx->infos->wolf->pos_y -= MO * mlx->infos->wolf->dir_y;
	}
	if (key == RIGHT_KEY)
	{
		mlx->infos->wolf->previous_dir_x = mlx->infos->wolf->dir_x;
		mlx->infos->wolf->dir_x = mlx->infos->wolf->dir_x * cosf(-RO) - mlx->infos->wolf->dir_y * sinf(-RO);
		mlx->infos->wolf->dir_y = mlx->infos->wolf->previous_dir_x * sinf(-RO) + mlx->infos->wolf->dir_y * cosf(-RO);
		mlx->infos->wolf->prev_plane_x = mlx->infos->wolf->plane_x;
		mlx->infos->wolf->plane_x = mlx->infos->wolf->plane_x * cosf(-RO) - mlx->infos->wolf->plane_y * sinf(-RO);
		mlx->infos->wolf->plane_y = mlx->infos->wolf->prev_plane_x * sinf(-RO) + mlx->infos->wolf->plane_y * cosf(-RO);
	}
	return (0);
}

int		deal_key(int key, t_mlx *mlx)
{
	if (key == ESCAPE_KEY)
		exit(0);
	else if (key == UP_KEY)
	{
		if (mlx->infos->wolf->map[(int)(mlx->infos->wolf->pos_x + MO * mlx->infos->wolf->dir_x)][(int)mlx->infos->wolf->pos_y] == 0)
			mlx->infos->wolf->pos_x += MO * mlx->infos->wolf->dir_x;
		if (mlx->infos->wolf->map[(int)mlx->infos->wolf->pos_x][(int)(mlx->infos->wolf->pos_y + MO * mlx->infos->wolf->dir_y)] == 0)
			mlx->infos->wolf->pos_y += MO * mlx->infos->wolf->dir_y;
	}
	else if (key == LEFT_KEY)
	{
		mlx->infos->wolf->previous_dir_x = mlx->infos->wolf->dir_x;
		mlx->infos->wolf->dir_x = mlx->infos->wolf->dir_x * cos(RO) - mlx->infos->wolf->dir_y * sin(RO);
		mlx->infos->wolf->dir_y = mlx->infos->wolf->previous_dir_x * sin(RO) + mlx->infos->wolf->dir_y * cos(RO);
		mlx->infos->wolf->prev_plane_x = mlx->infos->wolf->plane_x;
		mlx->infos->wolf->plane_x = mlx->infos->wolf->plane_x * cos(RO) - mlx->infos->wolf->plane_y * sin(RO);
		mlx->infos->wolf->plane_y = mlx->infos->wolf->prev_plane_x * sin(RO) + mlx->infos->wolf->plane_y * cos(RO);
	}
	else
		deal_key2(key, mlx);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	wolf_graph(mlx);
	return (0);
}

int		hook_close(t_wolf *wolf)
{
	(void)wolf;
	exit(0);
	return (0);
}
