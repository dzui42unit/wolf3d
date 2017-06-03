/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze_generator_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:33:22 by dzui              #+#    #+#             */
/*   Updated: 2017/03/08 18:33:29 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	go_up(int **maze, int i, int j, int size)
{
	if (maze[i - 2][j] != 0)
	{
		maze[i - 2][j] = 0;
		maze[i - 1][j] = 0;
		generation(maze, i - 2, j, size);
	}
}

void	go_down(int **maze, int i, int j, int size)
{
	if (maze[i + 2][j] != 0)
	{
		maze[i + 2][j] = 0;
		maze[i + 1][j] = 0;
		generation(maze, i + 2, j, size);
	}
}

void	go_left(int **maze, int i, int j, int size)
{
	if (maze[i][j - 2] != 0)
	{
		maze[i][j - 2] = 0;
		maze[i][j - 1] = 0;
		generation(maze, i, j - 2, size);
	}
}

void	go_right(int **maze, int i, int j, int size)
{
	if (maze[i][j + 2] != 0)
	{
		maze[i][j + 2] = 0;
		maze[i][j + 1] = 0;
		generation(maze, i, j + 2, size);
	}
}

void	set_exit(t_env *world)
{
	int i;
	int j;

	j = world->size - 1;
	i = world->size - 1;
	while (j > 1)
	{
		if (world->map[i - 1][j] == 0)
		{
			world->exit_x = i - 1;
			world->exit_y = j;
			break ;
		}
		j--;
	}
}
