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
			if (world->path_map[i][j] == -1)
				draw_rect(world, i, j, 0x00D3D3D3);
			if (i == (int)world->player.player_x
					&& j == (int)world->player.player_y)
				draw_rect(world, i, j, 0x000000FF);
			if (world->path_map[i][j] == -3 || world->path_map[i][j] > 0)
				draw_rect(world, i, j, 0x00000000);
			if (i == (int)world->exit_x && j == (int)world->exit_y)
				draw_rect(world, i, j, 0x000000FF);
			if (world->path_map[i][j] == -4 && world->path_activated)
				draw_rect(world, i, j, 0x0000A5FF);
			if (world->path_map[i][j] == -4 && !world->path_activated)
				draw_rect(world, i, j, 0x00000000);
			if (i == (int)world->player.player_x && j == (int)world->player.player_y)
				draw_rect(world, i, j, 0x0000FF00);
			j++;
		}
		i++;
	}
}
