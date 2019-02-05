/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:19:38 by gdrai             #+#    #+#             */
/*   Updated: 2019/02/05 16:19:20 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
#include <stdio.h>
# define WIDTH 1920
# define HEIGHT 1080
# define ESCAPE_KEY 53
# define SPACE_KEY 49
# define UP_KEY 126
# define W 13
# define DOWN_KEY 125
# define S 1
# define LEFT_KEY 123
# define A 0
# define RIGHT_KEY 124
# define D 2
# define LEFT_SHIFT 257
# define MO 0.05
# define RO 0.10
# define EXIT "wolf3d: finish"
# define ERR_MAP "Error: incorrect map"
# define ERR_MLX "Error: error mlx"
# define ERR_MALLOC "Error: error malloc"
# define ERR_OPCL "Error: error open or close"
# define ERR_USAGE "Usage: ./wolf3d <path_map>"

typedef struct	s_wolf
{
	char		*str;
	int			**map;
	int			map_height;
	int			map_width;
	int			step_x;
	int			step_y;
	int			key_press;
	int			hit;
	int			side;
	int			wall_height;
	int			nb_text;
	int			tex_x;
	int			tex_y;
	double		wall_x;
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
	double		wall_distance;
}				t_wolf;

typedef struct	s_img
{
	void		*xpm_img;
	void		*colorstone;
	void		*wood;
	void		*redbrick;
	void		*mossy;
	void		*alae;
	void		*purplestone;
	void		*eagle;
	void		*bluestone;
	void		*mlx_img;
	void		*mini_map;
	char		*data_mini_map;
	char		**data_texture;
	char		*data_img;
	char		*data_xpm;
	int			**map;
	int			bperpix;
	int			size_line;
	int			size_line_texture;
	int			size_line_mini_map;
	int			endian;
}				t_img;

typedef struct	s_infoswind
{
	int			width;
	int			height;
	int			size_texture;
	int			size_mini_map;
	int			put_mini_map;
	short		sprint;
	short		right;
	short		left;
	short		up;
	short		down;
	t_img		*img;
	t_wolf		*wolf;
}				t_infoswind;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*xpm_ptr;
	t_infoswind	*infos;
}				t_mlx;

/*
**	wolf_err.c
*/
void			wolf_err(int id);
void			wolf_exit(int id);

/*
**	wolf_init.c
*/
void			wolf_init(t_infoswind *infos);

/*
**	wolf_windows.c
*/
void			wolf_wind_init(t_mlx *mlx);
void			wolf_graph(t_mlx *mlx);
void			wolf_init_img(t_infoswind *window, t_img *img, void *mlx_ptr);

/*
**	wolf_calc.c
*/
void			wolf_calcul(t_mlx *mlx);
void			wait_for_hit(t_mlx *mlx);
void			pos_to_map(t_mlx *mlx);

/*
**	mini_map_calcul.c
*/

void			mini_map_calcul(t_mlx *mlx);

/*
**	hook.c
*/
int				hook_close(t_wolf *wolf);
int				deal_mouse(int mouse, int x, int y, t_mlx *mlx);
int				key_press(int key, t_mlx *mlx);
int				key_release(int key, t_mlx *mlx);
int				loop_hook(t_mlx *mlx);

/*
**	wolf_parsing.c
*/
void			parsing(t_wolf *wolf, char *argv);

/*
**	wolf_move.c
*/
void			wolf_move_left(t_mlx *mlx);
void			wolf_move_right(t_mlx *mlx);
void			wolf_move_up(t_mlx *mlx);
void			wolf_move_down(t_mlx *mlx);
void			wolf_move_sprint(t_mlx *mlx);

#endif
