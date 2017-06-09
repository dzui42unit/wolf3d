#include "wolf.h"

int		ft_find_path(t_env *world)
{
	int	stop;
	int x_dir[4] = { 1, -1, 0, 0 };
	int	y_dir[4] = { 0, 0, 1, -1 };
	int	flag;
	int i;
	int j;
	int d;
	int k;
	int i_x;
	int i_y;

	flag = 0;
	d = 0;
	world->path_map[(int)world->player.player_x][(int)world->player.player_y] = d;
	while (!flag && world->path_map[world->exit_x][world->exit_y] == -2)
	{
		flag = 1;
		i = 0;
		while (i < world->size)
		{
			j = 0;
			while (j < world->size)
			{
				if (world->path_map[i][j] == d)
				{
					k = 0;
					while (k < 4)
					{
						i_x = x_dir[k] + i;
						i_y = y_dir[k] + j;
						if (i_x >= 0 && i_x < world->size
							&& i_y >= 0 && i_y < world->size && (world->path_map[i_x][i_y] == -3
								|| world->path_map[i_x][i_y] == -2))
						{
							world->path_map[i_x][i_y] = d + 1;
							flag = 0;
						}
						k++;
					}
				}
				j++;
			}
			i++;
		}
		d++;
	}
	i = world->exit_x;
	j = world->exit_y;
	while (d > 0)
	{
		d--;
		k = 0;
		while (k < 4)
		{
			i_x = i + x_dir[k];
			i_y = j + y_dir[k];
			if (i_x >= 0 && i_x < world->size
				&& i_y >= 0 && i_y < world->size && world->path_map[i_x][i_y] == d)
			{
				world->path_map[i_x][i_y] = -4;
				i = i + x_dir[k];
				j = j + y_dir[k];
				break ;
			}
			k++;
		}
	}
}


void	make_new_maze(t_env *world)
{
	if ((int)world->player.player_x == world->exit_x
		&& (int)world->player.player_y == world->exit_y)
	{
		world->player.player_x = 2.5;
		world->player.player_y = 2.5;
		ft_free_map(world);
		start_generation(world);
	}
	ft_write_path_map(world);
}

void	ft_write_path_map(t_env *world)
{
	int i;
	int j;

	i = 0;
	while (i < world->size)
	{
		j = 0;
		while (j < world->size)
		{
			if (world->map[i][j] == 1 || world->map[i][j] == 2
				|| world->map[i][j] == 3 || world->map[i][j] == 4)
				world->path_map[i][j] = -1;
			if (world->map[i][j] == 0)
				world->path_map[i][j] = -3;
			if (i == world->exit_x && j == world->exit_y)
				world->path_map[i][j] = -2;
			j++;
		}
		i++;
	}
}

void	generation(int **maze, int i, int j, int size)
{
	int	*directions;
	int	k;

	directions = generate_direction();
	k = -1;
	while (++k < 4)
	{
		if (directions[k] == 1 && (i - 2 > 0))
			go_up(maze, i, j, size);
		else if (directions[k] == 2 && (j + 2 < size - 1))
			go_right(maze, i, j, size);
		else if (directions[k] == 3 && (i + 2 < size - 1))
			go_down(maze, i, j, size);
		else if (directions[k] == 4 && (j - 2 > 0))
			go_left(maze, i, j, size);
	}
}

void	start_generation(t_env *world)
{
	int i;
	int	j;

	srand(time(0));
	world->size = 39;
	generate_maze(world);
	i = 1 + rand() % (world->size - 10);
	while (i % 2 == 0)
		i = 1 + rand() % (world->size - 10);
	j = 1 + rand() % (world->size - 10);
	while (j % 2 == 0)
		j = 1 + rand() % (world->size - 10);
	world->map[i][j] = 0;
	generation(world->map, i, j, world->size);
	i = 1;
	while (++i < 4)
	{
		j = 1;
		while (++j < 4)
			world->map[i][j] = 0;
	}
	make_one(world->map, world->size);
	make_two(world->map, world->size);
	make_three(world->map, world->size);
	set_exit(world);
}

int		*generate_direction(void)
{
	int i;
	int	j;
	int temp;
	int	*directions;

	i = 0;
	directions = (int *)malloc(sizeof(int) * 4);
	while (i < 4)
	{
		directions[i] = i + 1;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = rand() % 4;
		while (j == i)
			j = rand() % 4;
		temp = directions[i];
		directions[i] = directions[j];
		directions[j] = temp;
		i++;
	}
	return (directions);
}
