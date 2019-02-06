/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:11:08 by gdrai             #+#    #+#             */
/*   Updated: 2019/02/06 10:43:27 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press(int key, t_mlx *mlx)
{
	if (key == RIGHT_KEY || key == D)
		mlx->infos->right = 1;
	else if (key == LEFT_KEY || key == A)
		mlx->infos->left = 1;
	else if (key == LEFT_SHIFT)
		mlx->infos->sprint = 1;
	else if (key == UP_KEY || key == W)
		mlx->infos->up = 1;
	else if (key == DOWN_KEY || key == S)
		mlx->infos->down = 1;
	return (0);
}

int		key_release(int key, t_mlx *mlx)
{
	if (key == SPACE_KEY)
		mlx->infos->put_mini_map = (mlx->infos->put_mini_map) ? 0 : 1;
	if (key == ESCAPE_KEY)
		wolf_exit(0);
	if (key == LEFT_SHIFT)
		mlx->infos->sprint = 0;
	if (key == RIGHT_KEY || key == D)
		mlx->infos->right = 0;
	else if (key == LEFT_KEY || key == A)
		mlx->infos->left = 0;
	else if (key == UP_KEY || key == W)
		mlx->infos->up = 0;
	else if (key == DOWN_KEY || key == S)
		mlx->infos->down = 0;
	return (0);
}

int		hook_close(t_wolf *wolf)
{
	(void)wolf;
	wolf_exit(0);
	return (0);
}

int		loop_hook(t_mlx *mlx)
{
	if (mlx->infos->up)
	{
		if (mlx->infos->sprint)
			wolf_move_sprint(mlx);
		else
			wolf_move_up(mlx);
	}
	if (mlx->infos->down)
		wolf_move_down(mlx);
	if (mlx->infos->right)
		wolf_move_right(mlx);
	if (mlx->infos->left)
		wolf_move_left(mlx);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	wolf_graph(mlx);
	return (0);
}
