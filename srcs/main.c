/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:11:17 by gdrai             #+#    #+#             */
/*   Updated: 2019/01/30 17:05:24 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	pos_to_map(t_ptr *ptr)
{
	if (ptr->dir_ray_x < 0)
	{
		ptr->step_x = -1;
		ptr->pos_to_map_x = (ptr->pos_x - ptr->map_x) * ptr->delta_x;
	}
	else
	{
		ptr->step_x = 1;
		ptr->pos_to_map_x = (ptr->map_x + 1.0 - ptr->pos_x) * ptr->delta_x;
	}
	if (ptr->dir_ray_y < 0)
	{
		ptr->step_y = -1;
		ptr->pos_to_map_y = (ptr->pos_y - ptr->map_y) * ptr->delta_y;
	}
	else
	{
		ptr->step_y = 1;
		ptr->pos_to_map_y = (ptr->map_y + 1.0 - ptr->pos_y) * ptr->delta_y;
	}
}

void	wait_for_hit(t_ptr *ptr)
{
	while (!ptr->hit)
	{
		if (ptr->pos_to_map_x <= ptr->pos_to_map_y)
		{
			ptr->pos_to_map_x += ptr->delta_x;
			ptr->map_x += ptr->step_x;
			ptr->side = 0;
		}
		else
		{
			ptr->pos_to_map_y += ptr->delta_y;
			ptr->map_y += ptr->step_y;
			ptr->side = 1;
		}
		ptr->hit = (ptr->map[(int)ptr->map_x][(int)ptr->map_y] > 0) ? 1 : 0;
	}
}

void	fill_screen(t_ptr *ptr, int i)
{
	int y;
	int j;

	y = -1;
	while (++y < ptr->wall_height / 2 && y < HEIGHT / 2)
	{
		j = 4 * ((HEIGHT / 2 + y) * WIDTH + i);
		ptr->my_img_string[j] = (char)0;
		ptr->my_img_string[j + 1] = (char)0;
		ptr->my_img_string[j + 2] = (ptr->side == 1) ? (char)140 : (char)180;
		j = 4 * ((HEIGHT / 2 - y) * WIDTH + i);
		ptr->my_img_string[j] = (char)0;
		ptr->my_img_string[j + 1] = (char)0;
		ptr->my_img_string[j + 2] = (ptr->side == 1) ? (char)140 : (char)180;
	}
	if (ptr->wall_height < HEIGHT)
	{
		while (ptr->wall_height / 2 < HEIGHT / 2)
		{
			j = 4 * ((HEIGHT / 2 + ptr->wall_height / 2) * WIDTH + i);
			ptr->my_img_string[j] = (char)0;
			ptr->my_img_string[j + 1] = (char)80;
			ptr->my_img_string[j + 2] = (char)0;
			j = 4 * ((HEIGHT / 2 - ptr->wall_height / 2) * WIDTH + i);
			ptr->my_img_string[j] = (unsigned int)ptr->my_xpm[j];
			ptr->my_img_string[j + 1] = (unsigned int)ptr->my_xpm[j + 1];
			ptr->my_img_string[j + 2] = (unsigned int)ptr->my_xpm[j + 2];
			ptr->wall_height++;
		}
	}
}

void	wolf_calcul(t_ptr *ptr)
{
	int i;

	i = -1;
	while (++i < WIDTH)
	{
		ptr->hit = 0;
		ptr->map_x = (int)ptr->pos_x;
		ptr->map_y = (int)ptr->pos_y;
		ptr->i_coord = 2 * (i / (double)WIDTH) - 1;
		ptr->dir_ray_x = ptr->dir_x + ptr->plane_x * ptr->i_coord;
		ptr->dir_ray_y = ptr->dir_y + ptr->plane_y * ptr->i_coord;
		ptr->delta_x = fabs(1 / ptr->dir_ray_x);
		ptr->delta_y = fabs(1 / ptr->dir_ray_y);
		pos_to_map(ptr);
		wait_for_hit(ptr);
		if (ptr->side == 0)
			ptr->wall_distance = (ptr->map_x - ptr->pos_x +
				(1 - ptr->step_x) / 2) / ptr->dir_ray_x;
		else
			ptr->wall_distance = (ptr->map_y - ptr->pos_y +
				(1 - ptr->step_y) / 2) / ptr->dir_ray_y;
		ptr->wall_height = (int)(HEIGHT / ptr->wall_distance);
		fill_screen(ptr, i);
	}
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
}

int		main(int argc, char **argv)
{
	t_ptr *ptr;

	if (argc == 2)
	{
		if (!(ptr = (t_ptr*)malloc(sizeof(t_ptr))))
			return (0);
		parsing(ptr, argv[1]);
		wolf_init(ptr);
		wolf_calcul(ptr);
		mlx_hook(ptr->win_ptr, 2, 5, deal_key, ptr);
		mlx_hook(ptr->win_ptr, 17, 1L << 0, hook_close, ptr);
		mlx_loop(ptr->mlx_ptr);
	}
	return (0);
}
