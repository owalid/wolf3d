/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:18:18 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/31 19:14:03 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			wolf_init_img(t_infoswind *window, t_img *img, void *mlx_ptr)
{
	if (!(img->mlx_img = mlx_new_image(mlx_ptr, window->width, window->height)))
		wolf_err(2);
	img->data_img = (char *)mlx_get_data_addr(img->mlx_img, 
			&img->bperpix, &img->size_line, &img->endian);
	if (!(img->xpm_img = mlx_xpm_file_to_image(mlx_ptr, 
					"./ressources/Image01.XPM", &window->width, &window->height)))
		wolf_err(2);
	img->data_xpm = (char *)mlx_get_data_addr(img->xpm_img, &img->bperpix, &img->size_line, &img->endian);
}

void			wolf_graph(t_mlx *mlx)
{
	t_img		img[1];

	wolf_init_img(mlx->infos, img, mlx->mlx_ptr);
	mlx->infos->img = img;
	wolf_calcul(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->infos->img->mlx_img, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->infos->img->mlx_img);
}

void			wolf_wind_init(t_infoswind *infos)
{
	t_mlx		mlx[1];

	if (!(mlx->mlx_ptr = mlx_init()))
		wolf_err(2);
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, infos->width, infos->height, "wolf3d")))
		wolf_err(2);
	mlx->infos = infos;
	wolf_graph(mlx);
	mlx_hook(mlx->win_ptr, 2, 5, deal_key, mlx);
	mlx_hook(mlx->win_ptr, 17, 1L << 0, hook_close, mlx);
	mlx_loop(mlx->mlx_ptr);
}
