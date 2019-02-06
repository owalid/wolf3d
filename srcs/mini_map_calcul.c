/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_calcul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:50:12 by gdrai             #+#    #+#             */
/*   Updated: 2019/02/06 10:39:06 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	fill_square(t_mlx *mlx, int x, int y, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			mlx->infos->img->data_mini_map[4 * (y * 2100 + i * 210
				+ x * 10 + j)] = (char)0;
			if (color)
				mlx->infos->img->data_mini_map[4 * (y * 2100 + i * 210
					+ x * 10 + j) + 1] = (char)255;
			else
				mlx->infos->img->data_mini_map[4 * (y * 2100 + i * 210
					+ x * 10 + j) + 2] = (char)255;
		}
	}
}

void	mini_map_calcul_bis(t_mlx *mlx, int i, int j)
{
	if ((int)mlx->infos->wolf->pos_x - i >= 0 && (int)mlx->infos->wolf->pos_y
		- j >= 0 && mlx->infos->wolf->map[(int)mlx->infos->wolf->pos_x - i]
			[(int)mlx->infos->wolf->pos_y - j] != 0)
		fill_square(mlx, 10 - i, 10 - j, 0);
	if ((int)mlx->infos->wolf->pos_x + i <= mlx->infos->wolf->map_height - 1
		&& (int)mlx->infos->wolf->pos_y - j >= 0 && mlx->infos->wolf->map
			[(int)mlx->infos->wolf->pos_x + i][(int)mlx->infos->wolf->pos_y - j]
				!= 0)
		fill_square(mlx, 10 + i, 10 - j, 0);
	if ((int)mlx->infos->wolf->pos_x - i >= 0 && (int)mlx->infos->wolf->pos_y
		+ j <= mlx->infos->wolf->map_width - 1 && mlx->infos->wolf->map
			[(int)mlx->infos->wolf->pos_x - i][(int)mlx->infos->wolf->pos_y + j]
				!= 0)
		fill_square(mlx, 10 - i, 10 + j, 0);
	if ((int)mlx->infos->wolf->pos_x + i <= mlx->infos->wolf->map_height - 1
		&& (int)mlx->infos->wolf->pos_y + j <= mlx->infos->wolf->map_width - 1
			&& mlx->infos->wolf->map[(int)mlx->infos->wolf->pos_x + i]
				[(int)mlx->infos->wolf->pos_y + j] != 0)
		fill_square(mlx, 10 + i, 10 + j, 0);
}

void	mini_map_calcul(t_mlx *mlx)
{
	int i;
	int j;

	i = -1;
	while (++i < 44100)
	{
		mlx->infos->img->data_mini_map[i * 4] = (char)255;
		mlx->infos->img->data_mini_map[i * 4 + 1] = (char)0;
		mlx->infos->img->data_mini_map[i * 4 + 2] = (char)0;
	}
	fill_square(mlx, 10, 10, 1);
	i = -1;
	while (++i <= 10)
	{
		j = -1;
		while (++j <= 10)
			mini_map_calcul_bis(mlx, i, j);
	}
}
