/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:31:04 by dzui              #+#    #+#             */
/*   Updated: 2017/03/16 16:44:56 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_rect(t_env *world, int i, int j, int color)
{
	int start_x;
	int	start_y;
	int	end_x;
	int	end_y;

	start_x = i * 6;
	start_y = j * 6;
	end_x = start_x + 6;
	end_y = start_y + 6;
	while (start_x < end_x)
	{
		start_y = j * 6;
		while (start_y < end_y)
		{
			put_pixel_to_img(world, start_x, start_y, color);
			start_y++;
		}
		start_x++;
	}
}

void	draw_map(t_env *world)
{
	int i;
	int j;

	i = 0;
	while (i < world->size)
	{
		j = 0;
		while (j < world->size)
		{
			if (world->map[i][j] > 0 && world->map[i][j])
				draw_rect(world, i, j, 0);
			else if (i == (int)world->player.player_x
					&& j == (int)world->player.player_y)
				draw_rect(world, i, j, 0x000000FF);
			else if (i == world->exit_x && j == world->exit_y)
				draw_rect(world, i, j, 0x00FF00FF);
			else
				draw_rect(world, i, j, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}
