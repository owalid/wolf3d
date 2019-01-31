/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:19:38 by gdrai             #+#    #+#             */
/*   Updated: 2019/01/30 17:03:40 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 611
# define ESCAPE_KEY 53
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define MO 0.4
# define RO 0.25

typedef struct	s_ptr
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	void		*xpm_ptr;
	char		*my_xpm;
	char		*my_img_string;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		*str;
	int			**map;
	int			map_height;
	int			map_width;
	int			step_x;
	int			step_y;
	int			key_press;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		previous_dir_x;
	double		dir_y;
	double		plane_x;
	double		prev_plane_x;
	double		plane_y;
	double		dir_ray_x;
	double		dir_ray_y;
	double		i_coord;
	double		map_x;
	double		map_y;
	double		pos_to_map_x;
	double		pos_to_map_y;
	double		delta_x;
	double		delta_y;
	int			hit;
	int			side;
	int			wall_height;
	double		wall_distance;
}				t_ptr;

int				deal_key(int key, t_ptr *ptr);
int				hook_close(t_ptr *ptr);
void			wolf_calcul(t_ptr *ptr);
void			parsing(t_ptr *ptr, char *argv);
int				deal_mouse(int mouse, int x, int y, t_ptr *ptr);
void			wolf_init(t_ptr *ptr);

#endif
