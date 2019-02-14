/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:03:59 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/02/14 12:17:14 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_parsing(t_wolf *wolf)
{
	int i;

	i = 0;
	while (wolf->str[i] != '\n' && wolf->str[i])
		i++;
	if (wolf->str[i] == '\0')
		wolf_err(1);
	wolf->map_width = i++;
	wolf->map_height = 1;
	while (wolf->str[i])
	{
		while (wolf->str[i] != '\n' && wolf->str[i])
			i++;
		if ((i + 1) % (wolf->map_width + 1) != 0)
			wolf_err(1);
		i++;
		wolf->map_height++;
	}
	if (wolf->map_height < 3 || wolf->map_width < 3)
		wolf_err(1);
}

void	fill_map(t_wolf *wolf)
{
	int i;
	int k;
	int j;
	int	**map;

	if (!(map = (int **)malloc(sizeof(int *) * wolf->map_height)))
		wolf_err(3);
	i = 0;
	j = 0;
	while (i < wolf->map_height)
	{
		k = 0;
		if (!(map[i] = (int *)malloc(sizeof(int) * wolf->map_width)))
			wolf_err(3);
		while (wolf->str[j] != '\n' && wolf->str[j])
			map[i][k++] = wolf->str[j++] - '0';
		j++;
		i++;
	}
	wolf->map = map;
}

void	check_map(t_wolf *wolf)
{
	int i;

	i = 0;
	if (wolf->map[1][1])
		wolf_err(1);
	while (i < wolf->map_width)
	{
		if (wolf->map[0][i] == 0 || wolf->map[wolf->map_height - 1][i] == 0)
			wolf_err(1);
		i++;
	}
	i = 0;
	while (i < wolf->map_height)
	{
		if (wolf->map[i][0] == 0 || wolf->map[i][wolf->map_width - 1] == 0)
			wolf_err(1);
		i++;
	}
}

void	parsing(t_wolf *wolf, char *argv)
{
	int		fd;
	char	*line;
	int		i;

	if (!(fd = open(argv, O_RDONLY, O_NOFOLLOW)))
		wolf_err(5);
	wolf->str = ft_strdup("\0");
	while (get_next_line(fd, &line) == 1)
	{
		wolf->str = ft_strjoin_free(wolf->str, line);
		ft_strdel(&line);
	}
	if ((close(fd) == -1))
		wolf_err(5);
	i = 0;
	while (wolf->str[i])
	{
		if (!ft_isdigit(wolf->str[i]) && wolf->str[i] != '\n')
			wolf_err(1);
		i++;
	}
	check_parsing(wolf);
	fill_map(wolf);
	check_map(wolf);
}
