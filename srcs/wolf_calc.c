/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:12:37 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/02/04 18:13:13 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	pos_to_map(t_mlx *mlx)
{
	if (mlx->infos->wolf->dir_ray_x < 0)
	{
		mlx->infos->wolf->step_x = -1;
		mlx->infos->wolf->pos_to_map_x = (mlx->infos->wolf->pos_x -
			mlx->infos->wolf->map_x) * mlx->infos->wolf->delta_x;
	}
	else
	{
		mlx->infos->wolf->step_x = 1;
		mlx->infos->wolf->pos_to_map_x = (mlx->infos->wolf->map_x + 1.0 -
			mlx->infos->wolf->pos_x) * mlx->infos->wolf->delta_x;
	}
	if (mlx->infos->wolf->dir_ray_y < 0)
	{
		mlx->infos->wolf->step_y = -1;
		mlx->infos->wolf->pos_to_map_y = (mlx->infos->wolf->pos_y -
			mlx->infos->wolf->map_y) * mlx->infos->wolf->delta_y;
	}
	else
	{
		mlx->infos->wolf->step_y = 1;
		mlx->infos->wolf->pos_to_map_y = (mlx->infos->wolf->map_y + 1.0 -
			mlx->infos->wolf->pos_y) * mlx->infos->wolf->delta_y;
	}
}

void	wait_for_hit(t_mlx *mlx)
{
	while (!mlx->infos->wolf->hit)
	{
		if (mlx->infos->wolf->pos_to_map_x <= mlx->infos->wolf->pos_to_map_y)
		{
			mlx->infos->wolf->pos_to_map_x += mlx->infos->wolf->delta_x;
			mlx->infos->wolf->map_x += mlx->infos->wolf->step_x;
			mlx->infos->wolf->side = 0;
		}
		else
		{
			mlx->infos->wolf->pos_to_map_y += mlx->infos->wolf->delta_y;
			mlx->infos->wolf->map_y += mlx->infos->wolf->step_y;
			mlx->infos->wolf->side = 1;
		}
		mlx->infos->wolf->hit = (mlx->infos->wolf->map[(int)mlx->infos->
			wolf->map_x][(int)mlx->infos->wolf->map_y] > 0) ? 1 : 0;
	}
}

void	fill_screen(t_mlx *mlx, int i)
{
	int start;
	int end;
	int j;
	int k;
	int l;

	if (HEIGHT - mlx->infos->wolf->wall_height <= 0)
	{
		start = -1;
		end = HEIGHT - 1;
	}
	else
	{
		start = (HEIGHT - mlx->infos->wolf->wall_height) / 2 - 1;
		end = HEIGHT - start - 1;
	}
	while (++start <= end)
	{
		k = start * 256 - HEIGHT * 128 + mlx->infos->wolf->wall_height * 128;
		mlx->infos->wolf->tex_y = ((k * 64) / mlx->infos->wolf->wall_height) / 256;
		j = 4 * (start * WIDTH + i);
		l = 4 * (mlx->infos->wolf->tex_x * 64 + mlx->infos->wolf->tex_y);
		if (j >= 0 && j < 2439998 && l >= 0 && l < 16382)
		{
			mlx->infos->img->data_img[j] = (unsigned int)mlx->infos->img->data_texture[mlx->infos->wolf->nb_text - 1][l];
			mlx->infos->img->data_img[j + 1] = (unsigned int)mlx->infos->img->data_texture[mlx->infos->wolf->nb_text - 1][l + 1];
			mlx->infos->img->data_img[j + 2] = (unsigned int)mlx->infos->img->data_texture[mlx->infos->wolf->nb_text - 1][l + 2];
		}
	}
	while (++end < HEIGHT)
	{
		j = 4 * (end * WIDTH + i);
		mlx->infos->img->data_img[j++] = (char)0;
		mlx->infos->img->data_img[j++] = (char)80;
		mlx->infos->img->data_img[j] = (char)0;
		j = 4 * ((HEIGHT - end) * WIDTH + i);
		mlx->infos->img->data_img[j] = (unsigned int)mlx->infos->img->data_xpm[j];
		mlx->infos->img->data_img[j + 1] = (unsigned int)mlx->infos->img->data_xpm[j + 1];
		mlx->infos->img->data_img[j + 2] = (unsigned int)mlx->infos->img->data_xpm[j + 2];
	}
}

void	wolf_calcul(t_mlx *mlx)
{
	int i;

	i = -1;
	while (++i < WIDTH)
	{
		mlx->infos->wolf->hit = 0;
		mlx->infos->wolf->map_x = (int)mlx->infos->wolf->pos_x;
		mlx->infos->wolf->map_y = (int)mlx->infos->wolf->pos_y;
		mlx->infos->wolf->i_coord = 2 * (i / (double)WIDTH) - 1;
		mlx->infos->wolf->dir_ray_x = mlx->infos->wolf->dir_x + mlx->infos->wolf->plane_x * mlx->infos->wolf->i_coord;
		mlx->infos->wolf->dir_ray_y = mlx->infos->wolf->dir_y + mlx->infos->wolf->plane_y * mlx->infos->wolf->i_coord;
		mlx->infos->wolf->delta_x = fabs(1 / mlx->infos->wolf->dir_ray_x);
		mlx->infos->wolf->delta_y = fabs(1 / mlx->infos->wolf->dir_ray_y);
		pos_to_map(mlx);
		wait_for_hit(mlx);
		mlx->infos->wolf->nb_text = mlx->infos->wolf->map[(int)mlx->infos->wolf->map_x][(int)mlx->infos->wolf->map_y];
		if (mlx->infos->wolf->side == 0)
		{
			mlx->infos->wolf->wall_distance = (mlx->infos->wolf->map_x - mlx->infos->wolf->pos_x +
				(1 - mlx->infos->wolf->step_x) / 2) / mlx->infos->wolf->dir_ray_x;
			mlx->infos->wolf->wall_x = mlx->infos->wolf->pos_y + mlx->infos->wolf->wall_distance *
				mlx->infos->wolf->dir_ray_y;
		}
		else
		{
			mlx->infos->wolf->wall_distance = (mlx->infos->wolf->map_y - mlx->infos->wolf->pos_y +
				(1 - mlx->infos->wolf->step_y) / 2) / mlx->infos->wolf->dir_ray_y;
			mlx->infos->wolf->wall_x = mlx->infos->wolf->pos_x + mlx->infos->wolf->wall_distance *
				mlx->infos->wolf->dir_ray_x;
		}
		mlx->infos->wolf->wall_x -= (int)mlx->infos->wolf->wall_x;
		mlx->infos->wolf->tex_x = (int)(mlx->infos->wolf->wall_x * (double)64);
		if ((mlx->infos->wolf->side == 0 && mlx->infos->wolf->dir_ray_x > 0) ||
			(mlx->infos->wolf->side == 1 && mlx->infos->wolf->dir_ray_y < 0))
			mlx->infos->wolf->tex_x = 64 - mlx->infos->wolf->tex_x - 1;
		mlx->infos->wolf->wall_height = (int)(HEIGHT / mlx->infos->wolf->wall_distance);
		fill_screen(mlx, i);
	}
}
