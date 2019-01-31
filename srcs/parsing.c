/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:19:47 by gdrai             #+#    #+#             */
/*   Updated: 2019/01/30 17:03:12 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_init(t_ptr *ptr)
{
	int width;
	int height;

	width = WIDTH;
	height = HEIGHT;
	ptr->pos_x = 2.5;
	ptr->pos_y = 2.5;
	ptr->dir_x = -1;
	ptr->dir_y = 0;
	ptr->plane_x = 0;
	ptr->plane_y = 0.66;
	ptr->bits_per_pixel = 32;
	ptr->size_line = WIDTH * 4;
	ptr->endian = 0;
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr,
		WIDTH, HEIGHT, "Wolf3d");
	ptr->img_ptr = mlx_new_image(ptr->mlx_ptr, WIDTH, HEIGHT);
	ptr->my_img_string = mlx_get_data_addr(ptr->img_ptr, &ptr->bits_per_pixel,
		&ptr->size_line, &ptr->endian);
	ptr->xpm_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr,
		"./ressources/Image01.XPM", &width, &height);
	ptr->my_xpm = mlx_get_data_addr(ptr->xpm_ptr, &ptr->bits_per_pixel,
		&ptr->size_line, &ptr->endian);
}

void	check_parsing(t_ptr *ptr)
{
	int i;

	i = 0;
	while (ptr->str[i] != '\n' && ptr->str[i])
		i++;
	if (ptr->str[i] == '\0')
		exit(write(1, "Error: Incorrect map\n", 21));
	ptr->map_width = i++;
	ptr->map_height = 1;
	while (ptr->str[i])
	{
		while (ptr->str[i] != '\n' && ptr->str[i])
			i++;
		if ((i + 1) % (ptr->map_width + 1) != 0)
			exit(write(1, "Error: Incorrect map\n", 21));
		i++;
		ptr->map_height++;
	}
	if (ptr->map_height < 3 || ptr->map_width < 3)
		exit(write(1, "Error: Incorrect map\n", 21));
}

void	fill_map(t_ptr *ptr)
{
	int i;
	int k;
	int j;

	if (!(ptr->map = (int**)malloc(sizeof(int*) * ptr->map_height)))
		exit(0);
	i = 0;
	j = 0;
	while (i < ptr->map_height)
	{
		k = 0;
		if (!(ptr->map[i] = (int*)malloc(sizeof(int) * ptr->map_width)))
			exit(0);
		while (ptr->str[j] != '\n' && ptr->str[j])
			ptr->map[i][k++] = ptr->str[j++] - '0';
		j++;
		i++;
	}
}

void	check_map(t_ptr *ptr)
{
	int i;

	i = 0;
	if (ptr->map[2][2])
		exit(write(1, "Error: Incorrect map\n", 21));
	while (i < ptr->map_width)
	{
		if (ptr->map[0][i] == 0 || ptr->map[ptr->map_height - 1][i] == 0)
			exit(write(1, "Error: Incorrect map\n", 21));
		i++;
	}
	i = 0;
	while (i < ptr->map_height)
	{
		if (ptr->map[i][0] == 0 || ptr->map[i][ptr->map_width - 1] == 0)
			exit(write(1, "Error: Incorrect map\n", 21));
		i++;
	}
}

void	parsing(t_ptr *ptr, char *argv)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(argv, O_RDONLY);
	ptr->str = ft_strdup("\0");
	while (get_next_line(fd, &line) == 1)
	{
		ptr->str = ft_strjoin_free(ptr->str, line);
		ft_strdel(&line);
	}
	i = 0;
	while (ptr->str[i])
	{
		if (!ft_isdigit(ptr->str[i]) && ptr->str[i] != '\n')
			exit(write(1, "Error: Incorrect map\n", 21));
		i++;
	}
	check_parsing(ptr);
	fill_map(ptr);
	check_map(ptr);
}
