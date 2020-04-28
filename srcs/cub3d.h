/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 03:37:48 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/26 19:13:41 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct	s_spr
{
	double	**sprite;
	double	*distance;
	double	sprite_x;
	double	sprite_y;
	double	inv;
	double	transform_x;
	double	transform_y;
	int		screen_x;
	int		height;
	int		width;
	int		start_y;
	int		end_y;
	int		start_x;
	int		end_x;
	int		amount;
	int		stripe;
	int		tex_x;
	int		tex_y;
}				t_spr;

typedef struct	s_map
{
	int		index;
	int		res_x;
	int		res_y;
	char	*n_text;
	char	*s_text;
	char	*e_text;
	char	*w_text;
	char	*spr_text;
	int		floor;
	int		ceiling;
	int		*map_x;
	int		map_y;
	int		**grid;
	int		**check;
	int		spawn_x;
	int		spawn_y;
	char	spawn_or;
	int		screenshot;
}				t_map;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*mlx_wdw;
	void	*img_new;
	void	*img_old;
	char	*addr;
	int		bpp;
	int		ls;
	int		end;
	int		render;
}				t_mlx;

typedef struct	s_data
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_x_old;
	double	dir_y;
	double	plane_x;
	double	plane_x_old;
	double	plane_y;
	double	cam_x;
	double	ray_x;
	double	ray_y;
	int		map_x;
	int		map_y;
	int		step_y;
	int		step_x;
	int		hit;
	int		side;
	double	dist_y;
	double	dist_x;
	double	delta_y;
	double	delta_x;
	double	*dist_wall;
	int		x;
	double	wall_x;
	int		wall_or;
	int		forward;
	int		backward;
	int		left;
	int		right;
	int		rotate_l;
	int		rotate_r;
}				t_data;

typedef struct	s_img
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		wall_height;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}				t_img;

typedef	struct	s_tex
{
	void	*tex_s;
	char	*addr_s;
	int		bpp_s;
	int		ls_s;
	int		end_s;
	int		y_s;
	int		x_s;
	void	*tex_w;
	char	*addr_w;
	int		bpp_w;
	int		ls_w;
	int		end_w;
	int		y_w;
	int		x_w;
	void	*tex_n;
	char	*addr_n;
	int		bpp_n;
	int		ls_n;
	int		end_n;
	int		y_n;
	int		x_n;
	void	*tex_e;
	char	*addr_e;
	int		bpp_e;
	int		ls_e;
	int		end_e;
	int		y_e;
	int		x_e;
	void	*tex_spr;
	char	*addr_spr;
	int		bpp_spr;
	int		ls_spr;
	int		end_spr;
	int		y_spr;
	int		x_spr;
}				t_tex;

typedef struct	s_meta
{
	t_data		*data;
	t_map		*map;
	t_mlx		*mlx;
	t_tex		*tex;
	t_img		*img;
	t_spr		*spr;
}				t_meta;

t_map			init_map(void);
t_data			init_data(void);
t_mlx			init_mlx(void);
t_img			init_img(void);
t_tex			init_tex(void);
t_spr			init_spr(void);
void			fill_data(t_data *data, t_map *map);
void			fill_tex(t_tex *tex, t_meta *meta);
void			fill_spr(t_spr *spr, t_map *map);
void			parse(char *av, t_map *map, t_data *data, t_spr *spr);
void			parse_file(t_map *map, char *map_str);
void			parse_res(t_map *map, char *map_str);
void			choice_aspect(t_map *map);
void			choice_small(t_map *map);
void			parse_path(t_map *map, char *map_str, int file);
void			parse_map(t_map *map, char *map_str);
void			parse_color(t_map *map, char *map_str, int object);
void			check_walls(t_map *map);
void			input_check(int ac, char **av, t_map *map);
void			error(int error);
int				image(t_meta *meta);
void			image_calculations(t_meta *meta);
void			differential_analysis(t_map *map, t_data *data);
void			build_image(t_meta *meta);
void			draw_sprite(t_meta *meta);
void			sprite_to_image(t_meta *meta);
void			make_screenshot(t_meta *meta);
int				key_press(int keycode, t_meta *meta);
int				key_release(int keycode, t_meta *meta);
void			move_forward(t_data *data, t_map *map);
void			move_backward(t_data *data, t_map *map);
void			move_left(t_data *data, t_map *map);
void			move_right(t_data *data, t_map *map);
void			rotate_left(t_data *data);
void			rotate_right(t_data *data);
int				exit_hook(t_meta *meta);
char			*ft_strdup(char *s);
int				ft_strlen(char *s);
char			*ft_strcat(char *origin, char *append);
int				ft_atoi(char *str);
void			ft_putstr(char *str);
int				ft_digitcount(unsigned long a, int base);

#endif
