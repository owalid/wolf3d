/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:11:08 by gdrai             #+#    #+#             */
/*   Updated: 2019/01/30 16:51:28 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		deal_key2(int key, t_ptr *ptr)
{
	if (key == DOWN_KEY)
	{
		if (ptr->map[(int)(ptr->pos_x - MO * ptr->dir_x)][(int)ptr->pos_y] == 0)
			ptr->pos_x -= MO * ptr->dir_x;
		if (ptr->map[(int)ptr->pos_x][(int)(ptr->pos_y - MO * ptr->dir_y)] == 0)
			ptr->pos_y -= MO * ptr->dir_y;
	}
	if (key == RIGHT_KEY)
	{
		ptr->previous_dir_x = ptr->dir_x;
		ptr->dir_x = ptr->dir_x * cosf(-RO) - ptr->dir_y * sinf(-RO);
		ptr->dir_y = ptr->previous_dir_x * sinf(-RO) + ptr->dir_y * cosf(-RO);
		ptr->prev_plane_x = ptr->plane_x;
		ptr->plane_x = ptr->plane_x * cosf(-RO) - ptr->plane_y * sinf(-RO);
		ptr->plane_y = ptr->prev_plane_x * sinf(-RO) + ptr->plane_y * cosf(-RO);
	}
	return (0);
}

int		deal_key(int key, t_ptr *ptr)
{
	if (key == ESCAPE_KEY)
		exit(0);
	else if (key == UP_KEY)
	{
		if (ptr->map[(int)(ptr->pos_x + MO * ptr->dir_x)][(int)ptr->pos_y] == 0)
			ptr->pos_x += MO * ptr->dir_x;
		if (ptr->map[(int)ptr->pos_x][(int)(ptr->pos_y + MO * ptr->dir_y)] == 0)
			ptr->pos_y += MO * ptr->dir_y;
	}
	else if (key == LEFT_KEY)
	{
		ptr->previous_dir_x = ptr->dir_x;
		ptr->dir_x = ptr->dir_x * cos(RO) - ptr->dir_y * sin(RO);
		ptr->dir_y = ptr->previous_dir_x * sin(RO) + ptr->dir_y * cos(RO);
		ptr->prev_plane_x = ptr->plane_x;
		ptr->plane_x = ptr->plane_x * cos(RO) - ptr->plane_y * sin(RO);
		ptr->plane_y = ptr->prev_plane_x * sin(RO) + ptr->plane_y * cos(RO);
	}
	else
		deal_key2(key, ptr);
	wolf_calcul(ptr);
	return (0);
}

int		hook_close(t_ptr *ptr)
{
	(void)ptr;
	exit(0);
	return (0);
}
