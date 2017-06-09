#include "wolf.h"

void	generate_maze(t_env *world)
{
	int	i;
	int	j;

	i = 0;
	world->map = (int **)malloc(sizeof(int *) * world->size);
	world->path_map = (int **)malloc(sizeof(int *) * world->size);
	while (i < world->size)
	{
		j = 0;
		world->map[i] = (int *)malloc(sizeof(int) * world->size);
		world->path_map[i] = (int *)malloc(sizeof(int) * world->size);
		while (j < world->size)
		{
			world->map[i][j] = 1;
			j++;
		}
		i++;
	}
}

void	make_one(int **map, int size)
{
	int i;
	int j;

	i = 1;
	while (i < size / 2)
	{
		j = size / 2;
		while (j < size - 1)
		{
			if (map[i][j] == 1)
				map[i][j] = 2;
			j++;
		}
		i++;
	}
}

void	make_two(int **map, int size)
{
	int i;
	int j;

	i = size / 2;
	while (i < size - 1)
	{
		j = 1;
		while (j < size / 2)
		{
			if (map[i][j] == 1)
				map[i][j] = 3;
			j++;
		}
		i++;
	}
}

void	make_three(int **map, int size)
{
	int i;
	int j;

	i = size / 2;
	while (i < size - 1)
	{
		j = size / 2;
		while (j < size - 1)
		{
			if (map[i][j] == 1)
				map[i][j] = 4;
			j++;
		}
		i++;
	}
}
