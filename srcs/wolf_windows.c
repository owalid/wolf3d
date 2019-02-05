/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:18:18 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/02/05 16:16:47 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			wolf_init_img(t_infoswind *window, t_img *img, void *mlx_ptr)
{
	img->bperpix = 32;
	img->size_line = WIDTH * 4;
	img->size_line_texture = 64 * 4;
	img->size_line_mini_map = 210 * 4;
	window->put_mini_map = 0;
	img->endian = 0;
	if (!(img->data_texture = (char **)malloc(sizeof(char *) * 9)))
		exit(0);
	if (!(img->mlx_img = mlx_new_image(mlx_ptr, window->width, window->height)))
		wolf_err(2);
	img->data_img = (char *)mlx_get_data_addr(img->mlx_img,
			&img->bperpix, &img->size_line, &img->endian);
	if (!(img->mini_map = mlx_new_image(mlx_ptr, window->size_mini_map, window->size_mini_map)))
		wolf_err(2);
	img->data_mini_map = (char *)mlx_get_data_addr(img->mini_map,
			&img->bperpix, &img->size_line_mini_map, &img->endian);
	if (!(img->xpm_img = mlx_xpm_file_to_image(mlx_ptr, 
		"./ressources/sunset.XPM", &window->width, &window->height)))
		wolf_err(2);
	img->data_xpm = (char *)mlx_get_data_addr(img->xpm_img,
		&img->bperpix, &img->size_line, &img->endian);
	if (!(img->colorstone = mlx_xpm_file_to_image(mlx_ptr, 
		"./ressources/colorstone.XPM", &window->size_texture, &window->size_texture)))
		wolf_err(2);
	img->data_texture[0] = (char *)mlx_get_data_addr(img->colorstone,
		&img->bperpix, &img->size_line_texture, &img->endian);
	if (!(img->wood = mlx_xpm_file_to_image(mlx_ptr, 
		"./ressources/wood.XPM", &window->size_texture, &window->size_texture)))
		wolf_err(2);
	img->data_texture[1] = (char *)mlx_get_data_addr(img->wood,
		&img->bperpix, &img->size_line_texture, &img->endian);
	if (!(img->redbrick = mlx_xpm_file_to_image(mlx_ptr, 
		"./ressources/redbrick.XPM", &window->size_texture, &window->size_texture)))
		wolf_err(2);
	img->data_texture[2] = (char *)mlx_get_data_addr(img->redbrick,
		&img->bperpix, &img->size_line_texture, &img->endian);
	if (!(img->purplestone = mlx_xpm_file_to_image(mlx_ptr, 
		"./ressources/purplestone.XPM", &window->size_texture, &window->size_texture)))
		wolf_err(2);
	img->data_texture[3] = (char *)mlx_get_data_addr(img->purplestone,
		&img->bperpix, &img->size_line_texture, &img->endian);
	if (!(img->mossy = mlx_xpm_file_to_image(mlx_ptr, 
		"./ressources/mossy.XPM", &window->size_texture, &window->size_texture)))
		wolf_err(2);
	img->data_texture[4] = (char *)mlx_get_data_addr(img->mossy,
		&img->bperpix, &img->size_line_texture, &img->endian);
	if (!(img->bluestone = mlx_xpm_file_to_image(mlx_ptr, 
		"./ressources/bluestone.XPM", &window->size_texture, &window->size_texture)))
		wolf_err(2);
	img->data_texture[5] = (char *)mlx_get_data_addr(img->bluestone,
		&img->bperpix, &img->size_line_texture, &img->endian);
	if (!(img->eagle = mlx_xpm_file_to_image(mlx_ptr, 
		"./ressources/eagle.XPM", &window->size_texture, &window->size_texture)))
		wolf_err(2);
	img->data_texture[6] = (char *)mlx_get_data_addr(img->eagle,
		&img->bperpix, &img->size_line_texture, &img->endian);
	if (!(img->alae = mlx_xpm_file_to_image(mlx_ptr, 
		"./ressources/alae.XPM", &window->size_texture, &window->size_texture)))
		wolf_err(2);
	img->data_texture[7] = (char *)mlx_get_data_addr(img->alae,
		&img->bperpix, &img->size_line_texture, &img->endian);
	img->data_texture[8] = (char *)mlx_get_data_addr(img->alae,
		&img->bperpix, &img->size_line_texture, &img->endian);
}

void			wolf_graph(t_mlx *mlx)
{
	wolf_calcul(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->infos->img->mlx_img, 0, 0);
	if (mlx->infos->put_mini_map == 1)
	{
		mini_map_calcul(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->infos->img->mini_map, 0, 0);
	}
}

void			wolf_wind_init(t_mlx *mlx)
{
	system("afplay sound/ameno.mp3&");
	wolf_graph(mlx);
	mlx_hook(mlx->win_ptr, 2, (1L << 0), key_press, mlx);
	mlx_hook(mlx->win_ptr, 3, (1L << 1), key_release, mlx);
	mlx_mouse_hook(mlx->win_ptr, deal_mouse, mlx);
	mlx_hook(mlx->win_ptr, 17, 1L << 0, hook_close, mlx);
	mlx_loop_hook(mlx->mlx_ptr, loop_hook, mlx);
	mlx_loop(mlx->mlx_ptr);
}
