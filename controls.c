#include "wolf.h"

void	ft_movement(t_env *world)
{
	if (world->flag.flag_w == 1)
		move_forward(&(world->player), world->map);
	if (world->flag.flag_r == 1)
		turn_right(&(world->player));
	if (world->flag.flag_s == 1)
		move_back(&(world->player), world->map);
	if (world->flag.flag_l == 1)
		turn_left(&(world->player));
}

int		press_key(int key_code, t_env *world)
{
	char	*number;

	number = ft_itoa(key_code);
	ft_putendl(number);
	free(number);
	if (key_code == 65307)
	{
		ft_putendl("exit!");
		exit(0);
	}
	if (key_code == 119)
		world->flag.flag_w = 1;
	if (key_code == 100)
		world->flag.flag_r = 1;
	if (key_code == 97)
		world->flag.flag_l = 1;
	if (key_code == 115)
		world->flag.flag_s = 1;
	if (key_code == 65505)
		world->player.speed_const = 5.0;
	if (key_code == 65507)
		world->player.speed_const = 0.5;
	if (key_code == 112)
	{
		world->path_activated = !world->path_activated;
	}
	return (0);
}

int		release_key(int key_code, t_env *world)
{
	if (key_code == 119)
		world->flag.flag_w = 0;
	if (key_code == 100)
		world->flag.flag_r = 0;
	if (key_code == 97)
		world->flag.flag_l = 0;
	if (key_code == 115)
		world->flag.flag_s = 0;
	if (key_code == 65505 || key_code == 65507)
		world->player.speed_const = 2.5;
	return (0);
}

int		my_key_func(int key_code, t_env *world)
{
	char	*number;

	number = ft_itoa(key_code);
	ft_putendl(number);
	free(number);
	if (key_code == 65307)
	{
		ft_putendl("exit!");
		exit(0);
	}
	if (key_code == 13)
		move_forward(&(world->player), world->map);
	if (key_code == 1)
		move_back(&(world->player), world->map);
	if (key_code == 123)
		turn_left(&(world->player));
	if (key_code == 124)
		turn_right(&(world->player));
	return (0);
}
