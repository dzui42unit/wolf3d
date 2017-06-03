/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze_generator_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:32:57 by dzui              #+#    #+#             */
/*   Updated: 2017/03/08 18:33:12 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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
