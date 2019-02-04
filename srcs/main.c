/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:11:17 by gdrai             #+#    #+#             */
/*   Updated: 2019/02/04 14:04:25 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_infoswind		infos[1];
	t_wolf			wolf[1];

	if (argc == 2)
	{
		infos->width = WIDTH;
		infos->height = HEIGHT;
		infos->size_texture = 64;
		parsing(wolf, argv[1]);
		infos->wolf = wolf;
		wolf_init(infos);
		wolf_wind_init(infos);
	}
	else
		wolf_err(4);
	return (0);
}
