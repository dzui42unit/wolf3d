/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:17:11 by dzui              #+#    #+#             */
/*   Updated: 2017/03/20 17:02:12 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# define WIDTH 860
# define HEIGHT 540
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <time.h>
# include <sys/times.h>

typedef struct	s_point
{
	float x;
	float y;
}				t_point;

typedef struct	s_line
{
	int		error1;
	int		error2;
	int		sign_x;
	int		sign_y;
	int		dx;
	int		dy;
	int		color;
}				t_line;

typedef struct	s_player
{
	double		old_plane_x;
	double		old_dir_x;
	double		plane_x;
	double		plane_y;
	double		player_x;
	double		player_y;
	double		dir_x;
	double		dir_y;
	double		camera_x;
	double		camera_y;
	double		speed;
	double		speed_const;
}				t_player;

typedef struct	s_raycast
{
	double		frame_time;
	double		time;
	double		old_time;
	double		ray_posx;
	double		ray_posy;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_distx;
	double		delta_disty;
	int			step_x;
	int			step_y;
	double		wall_dist;
	int			side;
	int			wall_height;
	double		wall_x;
	int			text_x;
	int			text_y;
}				t_raycast;

typedef struct	s_flag
{
	int flag_w;
	int flag_s;
	int flag_r;
	int flag_l;
}				t_flag;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			**map;
	int			*directions;
	int			size;
	int			start;
	int			end;
	t_player	player;
	t_raycast	rc;
	t_point		p1;
	t_point		p2;
	t_line		line;
	int			size_img;
	int			*data;
	int			bpp;
	int			endian;
	int			**text;
	int			t_h[4];
	int			t_w[4];
	int			d;
	int			exit_x;
	int			exit_y;
	int			color;
	t_flag		flag;
	int			hit;
}				t_env;

void			ft_free_map(t_env *world);
void			ft_free_text(t_env *world);
void			color_floor_celing(t_env *world, int x);
void			create_win_and_text(t_env *world);
void			set_crossing(t_env *world);
void			make_new_maze(t_env *world);
void			ft_draw_text(t_env *world, int x);
void			set_wall_height(t_env *world, t_raycast *rc);
void			draw_world(t_env *world);
void			ft_movement(t_env *world);
void			make_new_maze(t_env *world);
int				press_key(int key_code, t_env *world);
int				release_key(int key_code, t_env *world);
void			set_exit(t_env *world);
void			draw_rect(t_env *world, int i, int j, int color);
void			draw_map(t_env *world);
void			set_crossing(t_env *world);
void			generate_maze(t_env *world);
void			go_up(int **maze, int i, int j, int size);
void			go_down(int **maze, int i, int j, int size);
void			go_right(int **maze, int i, int j, int size);
void			go_left(int **maze, int i, int j, int size);
void			generation(int **maze, int i, int j, int size);
void			start_generation(t_env *world);
void			make_one(int **map, int size);
void			make_two(int **map, int size);
void			make_three(int **map, int size);
void			calc_frame_and_speed(t_env *world);
void			set_ray_init(t_player *pl, t_raycast *rc, int x);
void			set_step_dist(t_raycast *rc);
void			wall_hit(t_raycast *rc, int **level);
void			color_walls(t_env *world, t_raycast *rc, int **level);
void			put_pixel_to_img(t_env *world, int x, int y, int color);
void			clear_image(t_env *world);
void			draw_line(t_env *world);
void			move_forward(t_player *pl, int **level);
void			move_back(t_player *pl, int **level);
void			turn_left(t_player *pl);
void			turn_right(t_player *pl);
double			ft_floor(double number);
int				my_key_func(int key_code, t_env *world);
int				ft_wolf(t_env *world);
int				get_red(int color);
int				get_green(int color);
int				get_blue(int color);
int				*generate_direction(void);
void			ft_draw_controls(t_env *world);

#endif
