/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:11:15 by gdrai             #+#    #+#             */
/*   Updated: 2019/02/06 11:11:49 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	fill_special_texture_bis(t_mlx *mlx, int j, int l)
{
	if (mlx->infos->wolf->side == 1 && mlx->infos->wolf->dir_ray_y > 0)
	{
		mlx->infos->img->data_img[j] = (unsigned int)
			mlx->infos->img->data_texture[2][l];
		mlx->infos->img->data_img[j + 1] = (unsigned int)
			mlx->infos->img->data_texture[2][l + 1];
		mlx->infos->img->data_img[j + 2] = (unsigned int)
			mlx->infos->img->data_texture[2][l + 2];
	}
	else
	{
		mlx->infos->img->data_img[j] = (unsigned int)
			mlx->infos->img->data_texture[3][l];
		mlx->infos->img->data_img[j + 1] = (unsigned int)
			mlx->infos->img->data_texture[3][l + 1];
		mlx->infos->img->data_img[j + 2] = (unsigned int)
			mlx->infos->img->data_texture[3][l + 2];
	}
}

void	fill_special_texture(t_mlx *mlx, int j, int l)
{
	if (mlx->infos->wolf->side == 0 && mlx->infos->wolf->dir_ray_x > 0)
	{
		mlx->infos->img->data_img[j] = (unsigned int)
			mlx->infos->img->data_texture[8][l];
		mlx->infos->img->data_img[j + 1] = (unsigned int)
			mlx->infos->img->data_texture[8][l + 1];
		mlx->infos->img->data_img[j + 2] = (unsigned int)
			mlx->infos->img->data_texture[8][l + 2];
	}
	else if (mlx->infos->wolf->side == 0 && mlx->infos->wolf->dir_ray_x < 0)
	{
		mlx->infos->img->data_img[j] = (unsigned int)
			mlx->infos->img->data_texture[1][l];
		mlx->infos->img->data_img[j + 1] = (unsigned int)
			mlx->infos->img->data_texture[1][l + 1];
		mlx->infos->img->data_img[j + 2] = (unsigned int)
			mlx->infos->img->data_texture[1][l + 2];
	}
	else
		fill_special_texture_bis(mlx, j, l);
}

void	fill_wall(t_mlx *mlx, int start, int end, int i)
{
	int j;
	int k;
	int l;

	while (++start <= end)
	{
		k = start * 256 - HEIGHT * 128 + mlx->infos->wolf->wall_height * 128;
		mlx->infos->wolf->tex_y = ((k * 64) / mlx->infos->wolf->wall_height)
			/ 256;
		j = 4 * (start * WIDTH + i);
		l = 4 * (mlx->infos->wolf->tex_x * 64 + mlx->infos->wolf->tex_y);
		if (mlx->infos->wolf->nb_text == 9)
			fill_special_texture(mlx, j, l);
		else if (j >= 0 && j < WIDTH * HEIGHT * 4 - 2 && l >= 0 && l < 16382)
		{
			mlx->infos->img->data_img[j] = (unsigned int)
				mlx->infos->img->data_texture[mlx->infos->wolf->nb_text - 1][l];
			mlx->infos->img->data_img[j + 1] = (unsigned int)
				mlx->infos->img->data_texture[mlx->infos->wolf->nb_text - 1]
					[l + 1];
			mlx->infos->img->data_img[j + 2] = (unsigned int)
				mlx->infos->img->data_texture[mlx->infos->wolf->nb_text - 1]
					[l + 2];
		}
	}
}

void	fill_screen(t_mlx *mlx, int i)
{
	int start;
	int end;
	int j;

	start = (HEIGHT - mlx->infos->wolf->wall_height <= 0) ? -1 :
		(HEIGHT - mlx->infos->wolf->wall_height) / 2 - 1;
	end = (HEIGHT - mlx->infos->wolf->wall_height <= 0) ? HEIGHT - 1 :
		HEIGHT - start - 1;
	fill_wall(mlx, start, end, i);
	while (++end < HEIGHT)
	{
		j = 4 * (end * WIDTH + i);
		mlx->infos->img->data_img[j++] = (char)0;
		mlx->infos->img->data_img[j++] = (char)80;
		mlx->infos->img->data_img[j] = (char)0;
		j = 4 * ((HEIGHT - end) * WIDTH + i);
		mlx->infos->img->data_img[j] = (unsigned int)
			mlx->infos->img->data_xpm[j];
		mlx->infos->img->data_img[j + 1] = (unsigned int)
			mlx->infos->img->data_xpm[j + 1];
		mlx->infos->img->data_img[j + 2] = (unsigned int)
			mlx->infos->img->data_xpm[j + 2];
	}
}
