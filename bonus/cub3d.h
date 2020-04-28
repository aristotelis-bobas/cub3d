/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 19:50:23 by abobas        #+#    #+#                 */
/*   Updated: 2020/02/26 18:56:46 by abobas        ########   odam.nl         */
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
	int		audio_timer;
	double	dir_x;
	double	dir_y;
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
	char	*f_text;
	char	*c_text;
	char	*m_text;
	char	*sg_text;
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
	double	floor_x;
	double	floor_y;
	double	dist_player;
	double	current_dist;
	double	weight;
	double	current_x;
	double	current_y;
	int		x;
	double	wall_x;
	int		wall_or;
	int		forward;
	int		backward;
	int		left;
	int		right;
	int		rotate_l;
	int		rotate_r;
	int		mrotate_l;
	int		mrotate_r;
	int		mfire;
	int		mouse;
	int		use;
	int		health;
	int		hit_event;
	int		fire;
	int		shotgun;
	int		minigun;
	int		weapon_timer;
	int		weapon_audio_timer;
	int		boss_fight;
}				t_data;

typedef struct	s_img
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		wall_height;
	int		tex_x;
	int		tex_y;
	int		tex_x_floor;
	int		tex_y_floor;
	int		tex_x_ceiling;
	int		tex_y_ceiling;
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
	void	*tex_f;
	char	*addr_f;
	int		bpp_f;
	int		ls_f;
	int		end_f;
	int		y_f;
	int		x_f;
	void	*tex_c;
	char	*addr_c;
	int		bpp_c;
	int		ls_c;
	int		end_c;
	int		y_c;
	int		x_c;
	void	*tex_m;
	char	*addr_m;
	int		bpp_m;
	int		ls_m;
	int		end_m;
	int		y_m;
	int		x_m;
	void	*tex_sg;
	char	*addr_sg;
	int		bpp_sg;
	int		ls_sg;
	int		end_sg;
	int		y_sg;
	int		x_sg;
	void	*tex_mg;
	char	*addr_mg;
	int		bpp_mg;
	int		ls_mg;
	int		end_mg;
	int		y_mg;
	int		x_mg;
}				t_tex;

typedef struct	s_ani
{
	void	*sg_1;
	char	*addr_sg1;
	int		bpp_sg1;
	int		ls_sg1;
	int		end_sg1;
	int		y_sg1;
	int		x_sg1;
	void	*sg_2;
	char	*addr_sg2;
	int		bpp_sg2;
	int		ls_sg2;
	int		end_sg2;
	int		y_sg2;
	int		x_sg2;
	void	*sg_3;
	char	*addr_sg3;
	int		bpp_sg3;
	int		ls_sg3;
	int		end_sg3;
	int		y_sg3;
	int		x_sg3;
	void	*sg_4;
	char	*addr_sg4;
	int		bpp_sg4;
	int		ls_sg4;
	int		end_sg4;
	int		y_sg4;
	int		x_sg4;
	void	*ex_1;
	char	*addr_ex1;
	int		bpp_ex1;
	int		ls_ex1;
	int		end_ex1;
	int		y_ex1;
	int		x_ex1;
	void	*ex_2;
	char	*addr_ex2;
	int		bpp_ex2;
	int		ls_ex2;
	int		end_ex2;
	int		y_ex2;
	int		x_ex2;
	void	*ex_3;
	char	*addr_ex3;
	int		bpp_ex3;
	int		ls_ex3;
	int		end_ex3;
	int		y_ex3;
	int		x_ex3;
	void	*ex_4;
	char	*addr_ex4;
	int		bpp_ex4;
	int		ls_ex4;
	int		end_ex4;
	int		y_ex4;
	int		x_ex4;
	void	*mg_1;
	char	*addr_mg1;
	int		bpp_mg1;
	int		ls_mg1;
	int		end_mg1;
	int		y_mg1;
	int		x_mg1;
	void	*mg_2;
	char	*addr_mg2;
	int		bpp_mg2;
	int		ls_mg2;
	int		end_mg2;
	int		y_mg2;
	int		x_mg2;
	void	*mg_3;
	char	*addr_mg3;
	int		bpp_mg3;
	int		ls_mg3;
	int		end_mg3;
	int		y_mg3;
	int		x_mg3;
}				t_ani;

typedef struct	s_mini
{
	int		start_x;
	int		end_x;
	int		start_y;
	int		end_y;
}				t_mini;

typedef struct	s_meta
{
	t_data		*data;
	t_map		*map;
	t_mlx		*mlx;
	t_tex		*tex;
	t_img		*img;
	t_spr		*spr;
	t_ani		*ani;
}				t_meta;

t_map			init_map(void);
t_data			init_data(void);
t_mlx			init_mlx(void);
t_img			init_img(void);
t_tex			init_tex(void);
t_spr			init_spr(void);
t_ani			init_ani(t_meta *meta);
t_mini			init_mini(t_meta *meta);
void			fill_data(t_data *data, t_map *map);
void			fill_tex(t_tex *tex, t_meta *meta);
void			fill_spr(t_spr *spr, t_map *map);
char			*read_file(int fd, char *dst);
void			parse(char *av, t_map *map, t_data *data, t_spr *spr);
void			parse_file(t_map *map, char *map_str);
void			parse_res(t_map *map, char *map_str);
void			choice_aspect(t_map *map);
void			choice_small(t_map *map);
void			parse_path(t_map *map, char *map_str, int file);
void			parse_map(t_map *map, char *map_str);
void			free_struct_sprite(t_spr *spr);
void			free_struct_map(t_map *map);
void			new_map_1(t_map *map);
void			new_sprite_1(t_spr *spr, t_tex *tex, t_meta *meta);
void			check_walls(t_map *map);
void			input_check(int ac, char **av, t_map *map);
void			error(int error);
int				image(t_meta *meta);
void			exchange_img(t_mlx *mlx);
void			new_img(t_mlx *mlx, t_map *map);
void			image_calculations(t_meta *meta);
void			build_floor_ceiling(t_meta *meta);
void			differential_analysis(t_map *map, t_data *data);
void			build_image(t_meta *meta);
void			draw_sprite(t_meta *meta);
void			substitute_sprite(t_spr *spr, int i);
void			move_sprite(t_spr *spr, t_data *data, t_map *map, int i);
int				get_color_tex_2(t_meta *meta, int i, int d);
int				damaged_sprite(int color);
void			check_object(t_spr *spr, t_data *data);
void			check_object_2(t_spr *spr, t_data *data, int i);
void			sprite_to_image(t_meta *meta, int i);
int				explosion_sprite_color(t_meta *meta, int i, int d);
void			explosion_sprite_x(t_meta *meta, int i);
void			handle_animation_sprite(t_meta *meta, int i);
void			make_screenshot(t_meta *meta);
void			put_hud(t_meta *meta);
void			put_minimap(t_meta *meta);
void			put_shotgun(t_meta *meta);
void			put_crosshair(t_meta *meta);
void			put_shotgun_animation(t_meta *meta);
int				get_shotgun_fire_texel(t_meta *meta, int x, int y);
void			put_shotgun_shell(t_meta *meta);
void			put_shotgun_reloaded(t_meta *meta);
void			put_minigun(t_meta *meta);
void			put_minigun_animation(t_meta *meta);
void			put_minigun_rot(t_meta *meta);
void			put_healthbar_boss(t_meta *meta);
void			game_over(t_meta *meta);
void			game_win(t_meta *meta);
void			boss_fight(t_meta *meta);
void			check_population(t_meta *meta);
int				key_press(int keycode, t_meta *meta);
int				key_release(int keycode, t_meta *meta);
int				mouse_press(int button, int x, int y, t_meta *meta);
int				mouse_register(int x, int y, t_meta *meta);
void			move_forward(t_data *data, t_map *map);
void			move_backward(t_data *data, t_map *map);
void			move_left(t_data *data, t_map *map);
void			move_right(t_data *data, t_map *map);
int				check_forward(t_data *data, t_spr *spr);
int				check_backward(t_data *data, t_spr *spr);
int				check_left(t_data *data, t_spr *spr);
int				check_right(t_data *data, t_spr *spr);
void			rotate_left(t_data *data);
void			rotate_right(t_data *data);
void			use(t_data *data, t_map *map);
void			fire(t_data *data, t_meta *meta);
void			fire_weapon(t_meta *meta);
int				exit_hook(t_meta *meta);
char			*ft_strdup(char *s);
int				ft_strlen(char *s);
char			*ft_strcat(char *origin, char *append);
int				ft_atoi(char *str);
void			ft_putstr(char *str);
int				ft_digitcount(unsigned long a, int base);

#endif
