#include "wolf.h"

void	calc_frame_and_speed(t_env *world)
{
	double	temp;

	world->rc.old_time = world->rc.time;
	world->rc.time = clock();
	temp = (world->rc.time - world->rc.old_time) / CLOCKS_PER_SEC;
	world->rc.frame_time = temp;
	world->player.speed = world->rc.frame_time;
	world->player.speed *= world->player.speed_const;
}

void	ft_free_text(t_env *world)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(world->text[i]);
		i++;
	}
}

void	ft_free_map(t_env *world)
{
	int i;

	i = 0;
	while (i < world->size)
	{
		free(world->map[i]);
		i++;
	}
}
