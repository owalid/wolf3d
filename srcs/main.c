/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:11:17 by gdrai             #+#    #+#             */
/*   Updated: 2019/02/04 18:10:29 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_infoswind		infos[1];
	t_wolf			wolf[1];
	t_img			img[1];
	t_mlx			mlx[1];

	if (argc == 2)
	{
		infos->width = WIDTH;
		infos->height = HEIGHT;
		infos->size_texture = 64;
		parsing(wolf, argv[1]);
		infos->wolf = wolf;
		wolf_init(infos);
		if (!(mlx->mlx_ptr = mlx_init()))
			wolf_err(2);
		if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, infos->width, infos->height, "wolf3d")))
			wolf_err(2);
		wolf_init_img(infos, img, mlx->mlx_ptr);
		infos->img = img;
		mlx->infos = infos;
		wolf_wind_init(mlx);
	}
	else
		wolf_err(4);
	return (0);
}
