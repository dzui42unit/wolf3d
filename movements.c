/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:27:45 by dzui              #+#    #+#             */
/*   Updated: 2017/03/16 16:27:51 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	move_forward(t_player *pl, int **map)
{
	if (!map[(int)(pl->player_x + pl->dir_x * pl->speed)][(int)(pl->player_y)])
		pl->player_x += pl->dir_x * pl->speed;
	if (!map[(int)(pl->player_x)][(int)(pl->player_y + pl->dir_y * pl->speed)])
		pl->player_y += pl->dir_y * pl->speed;
}

void	move_back(t_player *pl, int **map)
{
	if (!map[(int)(pl->player_x - pl->dir_x * pl->speed)][(int)(pl->player_y)])
		pl->player_x -= pl->dir_x * pl->speed;
	if (!map[(int)(pl->player_x)][(int)(pl->player_y - pl->dir_y * pl->speed)])
		pl->player_y -= pl->dir_y * pl->speed;
}

void	turn_left(t_player *pl)
{
	pl->old_dir_x = pl->dir_x;
	pl->dir_x = pl->dir_x * cos(0.05) - pl->dir_y * sin(0.05);
	pl->dir_y = pl->old_dir_x * sin(0.05) + pl->dir_y * cos(0.05);
	pl->old_plane_x = pl->plane_x;
	pl->plane_x = pl->plane_x * cos(0.05) - pl->plane_y * sin(0.05);
	pl->plane_y = pl->old_plane_x * sin(0.05) + pl->plane_y * cos(0.05);
}

void	turn_right(t_player *pl)
{
	pl->old_dir_x = pl->dir_x;
	pl->dir_x = pl->dir_x * cos(-0.05) - pl->dir_y * sin(-0.05);
	pl->dir_y = pl->old_dir_x * sin(-0.05) + pl->dir_y * cos(-0.05);
	pl->old_plane_x = pl->plane_x;
	pl->plane_x = pl->plane_x * cos(-0.05) - pl->plane_y * sin(-0.05);
	pl->plane_y = pl->old_plane_x * sin(-0.05) + pl->plane_y * cos(-0.05);
}
