/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:02:25 by dzui              #+#    #+#             */
/*   Updated: 2017/03/20 17:02:33 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_wolf(t_env *w)
{
	int x;

	x = 0;
	clear_image(w);
	while (x < WIDTH)
	{
		set_ray_init(&(w->player), &(w->rc), x);
		set_step_dist(&(w->rc));
		wall_hit(&(w->rc), w->map);
		set_wall_height(w, &(w->rc));
		ft_draw_text(w, x);
		color_floor_celing(w, x);
		x++;
	}
	calc_frame_and_speed(w);
	ft_movement(w);
	draw_map(w);
	set_crossing(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	ft_draw_controls(w);
	make_new_maze(w);
	return (0);
}

void	create_win_and_text(t_env *w)
{
	void	*temp;
	int		b;

	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, WIDTH, HEIGHT, "Wolf3D");
	w->img = mlx_new_image(w->mlx, WIDTH, HEIGHT);
	w->text = (int **)malloc(sizeof(int *) * 4);
	temp = mlx_xpm_file_to_image(w->mlx, "2.xpm", &(w->t_h[0]), &(w->t_w[0]));
	w->text[0] = (int *)mlx_get_data_addr(temp, &b, &b, &b);
	temp = mlx_xpm_file_to_image(w->mlx, "1.xpm", &(w->t_h[1]), &(w->t_w[1]));
	w->text[1] = (int *)mlx_get_data_addr(temp, &b, &b, &b);
	temp = mlx_xpm_file_to_image(w->mlx, "3.xpm", &(w->t_h[2]), &(w->t_w[2]));
	w->text[2] = (int *)mlx_get_data_addr(temp, &b, &b, &b);
	temp = mlx_xpm_file_to_image(w->mlx, "3.xpm", &(w->t_h[3]), &(w->t_w[3]));
	w->text[3] = (int *)mlx_get_data_addr(temp, &b, &b, &b);
	w->data = (int *)mlx_get_data_addr(w->img, &b, &b, &b);
}

int		main(void)
{
	t_env	w;

	start_generation(&w);
	w.player.player_x = 2.5;
	w.player.player_y = 2.5;
	w.player.dir_x = -1;
	w.player.dir_y = 0;
	w.player.plane_x = 0;
	w.player.plane_y = 0.66;
	w.player.speed_const = 2.5;
	w.flag.flag_w = 0;
	w.flag.flag_l = 0;
	w.flag.flag_r = 0;
	w.flag.flag_s = 0;
	w.rc.time = 0.0;
	w.rc.old_time = 0.0;
	create_win_and_text(&w);
	mlx_hook(w.win, 2, 1, press_key, &w);
	mlx_hook(w.win, 3, 2, release_key, &w);
	mlx_loop_hook(w.mlx, ft_wolf, &w);
	mlx_loop(w.mlx);
	return (0);
}

void	ft_draw_controls(t_env *world)
{
	mlx_string_put(world->mlx, world->win, 10, HEIGHT - 70, 0x00FFFF00, "W/A/S/D to move");
	mlx_string_put(world->mlx, world->win, 10, HEIGHT - 60, 0x00FFFF00, "Lelft Shift to accelerate");
	mlx_string_put(world->mlx, world->win, 10, HEIGHT - 50, 0x00FFFF00, "Ctrl to slow down movement");
	mlx_string_put(world->mlx, world->win, 10, HEIGHT - 40, 0x00FFFF00, "ESC to exit");
}
