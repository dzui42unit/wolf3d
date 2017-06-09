#include "wolf.h"

void	put_pixel_to_img(t_env *w, int x, int y, int color)
{
	char	*px;
	int		p;

	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		px = mlx_get_data_addr(w->img, &p, &p, &p);
		p = WIDTH * y * 4 + x * 4;
		px[p + 0] = get_red(color);
		px[p + 1] = get_green(color);
		px[p + 2] = get_blue(color);
	}
}

void	clear_image(t_env *w)
{
	char	*px;
	int		p;

	px = mlx_get_data_addr(w->img, &p, &p, &p);
	ft_bzero(px, 4 * WIDTH * HEIGHT);
}

void	draw_line(t_env *w)
{
	w->line.dx = fabs(w->p2.x - w->p1.x);
	w->line.dy = fabs(w->p2.y - w->p1.y);
	w->line.sign_x = w->p1.x < w->p2.x ? 1 : -1;
	w->line.sign_y = w->p1.y < w->p2.y ? 1 : -1;
	w->line.error1 = w->line.dx - w->line.dy;
	while (w->p1.x != w->p2.x || w->p1.y != w->p2.y)
	{
		put_pixel_to_img(w, w->p1.x, w->p1.y, w->line.color);
		w->line.error2 = w->line.error1 * 2;
		if (w->line.error2 > -(w->line.dy))
		{
			w->line.error1 -= w->line.dy;
			w->p1.x += w->line.sign_x;
		}
		if (w->line.error2 < w->line.dx)
		{
			w->line.error1 += w->line.dx;
			w->p1.y += w->line.sign_y;
		}
	}
}

void	set_crossing(t_env *w)
{
	w->p1.x = WIDTH / 2 - 10;
	w->p2.x = WIDTH / 2 + 10;
	w->p1.y = HEIGHT / 2;
	w->p2.y = HEIGHT / 2;
	w->line.color = 0x00FFFFFF;
	draw_line(w);
	w->line.color = 0x00FFFFFF;
	w->p1.x = WIDTH / 2;
	w->p2.x = WIDTH / 2;
	w->p1.y = HEIGHT / 2 - 10;
	w->p2.y = HEIGHT / 2 + 10;
	draw_line(w);
}

void	ft_draw_text(t_env *w, int x)
{
	int i;

	i = w->map[w->rc.map_x][w->rc.map_y] - 1;
	if (w->rc.side == 0)
		w->rc.wall_x = w->rc.ray_posy + w->rc.wall_dist * w->rc.ray_dir_y;
	else
		w->rc.wall_x = w->rc.ray_posx + w->rc.wall_dist * w->rc.ray_dir_x;
	w->rc.wall_x -= floor((w->rc.wall_x));
	w->rc.text_x = (int)(w->rc.wall_x * (double)(w->t_w[i]));
	if (w->rc.side == 0 && w->rc.ray_dir_x > 0)
		w->rc.text_x = w->t_w[i] - w->rc.text_x - 1;
	if (w->rc.side == 1 && w->rc.ray_dir_y < 0)
		w->rc.text_x = w->t_w[i] - w->rc.text_x - 1;
	while (w->start != w->end)
	{
		w->d = w->start * 256 - HEIGHT * 128 + w->rc.wall_height * 128;
		w->rc.text_y = ((w->d * w->t_h[i]) / w->rc.wall_height) / 256;
		if (w->rc.wall_height * w->rc.text_y + w->rc.text_x < 0)
			return ;
		w->color = w->text[i][w->t_h[i] * w->rc.text_y + w->rc.text_x];
		if (w->rc.side == 1)
			w->color = (w->color >> 1) & 8355711;
		w->data[x + WIDTH * w->start] = w->color;
		w->start++;
	}
}
