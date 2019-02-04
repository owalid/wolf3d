/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:11:08 by gdrai             #+#    #+#             */
/*   Updated: 2019/02/04 18:09:46 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press(int key, t_mlx *mlx)
{
	if (key == RIGHT_KEY)
		mlx->infos->right = 1;
	else if (key == LEFT_KEY)
		mlx->infos->left = 1;
	else if (key == UP_KEY)
		mlx->infos->up = 1;
	else if (key == DOWN_KEY)
		mlx->infos->down = 1;
	return (0);
}

int		key_release(int key, t_mlx *mlx)
{
	if (key == ESCAPE_KEY)
		wolf_exit(0);
	if (key == RIGHT_KEY)
		mlx->infos->right = 0;
	else if (key == LEFT_KEY)
		mlx->infos->left = 0;
	else if (key == UP_KEY)
		mlx->infos->up = 0;
	else if (key == DOWN_KEY)
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
		wolf_move_up(mlx);
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
