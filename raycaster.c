#include "wolf.h"

void	set_ray_init(t_player *pl, t_raycast *rc, int x)
{
	pl->camera_x = 2 * x / (double)(WIDTH) - 1;
	rc->ray_posx = pl->player_x;
	rc->ray_posy = pl->player_y;
	rc->ray_dir_x = pl->dir_x + pl->plane_x * pl->camera_x;
	rc->ray_dir_y = pl->dir_y + pl->plane_y * pl->camera_x;
	rc->map_x = (int)(rc->ray_posx);
	rc->map_y = (int)(rc->ray_posy);
	rc->delta_distx = (rc->ray_dir_y * rc->ray_dir_y);
	rc->delta_distx = rc->delta_distx / (rc->ray_dir_x * rc->ray_dir_x);
	rc->delta_distx = sqrt(1 + rc->delta_distx);
	rc->delta_disty = rc->ray_dir_x * rc->ray_dir_x;
	rc->delta_disty = rc->delta_disty / (rc->ray_dir_y * rc->ray_dir_y);
	rc->delta_disty = sqrt(rc->delta_disty + 1);
}

void	set_step_dist(t_raycast *rc)
{
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (rc->ray_posx - rc->map_x) * rc->delta_distx;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0 - rc->ray_posx) * rc->delta_distx;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (rc->ray_posy - rc->map_y) * rc->delta_disty;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0 - rc->ray_posy) * rc->delta_disty;
	}
}

void	wall_hit(t_raycast *rc, int **level)
{
	while (1)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_distx;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist_y += rc->delta_disty;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if ((level[rc->map_x][rc->map_y] > 0)
			&& (level[rc->map_x][rc->map_y] != 9))
			break ;
	}
}

void	set_wall_height(t_env *world, t_raycast *rc)
{
	if (rc->side == 0)
	{
		rc->wall_dist = (rc->map_x - rc->ray_posx + (1 - rc->step_x) / 2);
		rc->wall_dist /= rc->ray_dir_x;
	}
	else
	{
		rc->wall_dist = (rc->map_y - rc->ray_posy + (1 - rc->step_y) / 2);
		rc->wall_dist /= rc->ray_dir_y;
	}
	rc->wall_height = (int)(HEIGHT / rc->wall_dist);
	world->rc.wall_height = (int)(HEIGHT / world->rc.wall_dist);
	world->start = -world->rc.wall_height / 2 + HEIGHT / 2;
	if (world->start < 0)
		world->start = 0;
	world->end = world->rc.wall_height / 2 + HEIGHT / 2;
	if (world->end >= HEIGHT)
		world->end = HEIGHT - 1;
}
