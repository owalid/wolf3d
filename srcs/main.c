/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:11:17 by gdrai             #+#    #+#             */
/*   Updated: 2019/02/06 17:46:22 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	info_init(t_infoswind *infos)
{
	infos->width = WIDTH;
	infos->height = HEIGHT;
	infos->size_texture = 64;
	infos->size_mini_map = 210;
}

void	wolf_verif_ext(char *file)
{
	int		i;

	i = ft_strlen(file) - 4;
	if (i <= 0 || ft_strcmp(file + i, ".w3d"))
		wolf_err(1);
}

int		main(int argc, char **argv)
{
	t_infoswind		infos[1];
	t_wolf			wolf[1];
	t_img			img[1];
	t_mlx			mlx[1];

	if (argc == 2)
	{
		wolf_verif_ext(argv[1]);
		info_init(infos);
		parsing(wolf, argv[1]);
		infos->wolf = wolf;
		wolf_init(infos);
		if (!(mlx->mlx_ptr = mlx_init()))
			wolf_err(2);
		if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
			infos->width, infos->height, "wolf3d")))
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
