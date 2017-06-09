#include "wolf.h"

int		get_red(int color)
{
	return ((int)(((color >> 16) & 0xFF)));
}

int		get_green(int color)
{
	return ((int)(((color >> 8) & 0xFF)));
}

int		get_blue(int color)
{
	return ((int)((color) & 0xFF));
}

void	color_floor_celing(t_env *world, int x)
{
	int y;
	int	lim;

	if (world->end < 0)
		world->end = HEIGHT;
	y = world->end;
	lim = HEIGHT - world->start;
	while (y <= HEIGHT)
	{
		put_pixel_to_img(world, x, y, 0x00BDBDBD);
		y++;
	}
	y = 0;
	while (y < lim)
	{
		put_pixel_to_img(world, x, y, 0x00FBDEBB);
		y++;
	}
}
