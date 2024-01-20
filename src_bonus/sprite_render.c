/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:07:19 by alappas           #+#    #+#             */
/*   Updated: 2024/01/20 17:07:21 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	sprite_locate(t_game *game)

{
	int		y;
	int		x;
	int		i;
	char	**map;

	map = game->map;
	y = -1;
	i = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '2')
			{
				game->sprite->x[i] = x + 0.5;
				game->sprite->y[i] = y + 0.5;
				i++;
			}
		}
	}
}

void	sort_sprites(t_game *game)

{
	int		i;
	double	tmp;

	i = 0;
	while (game->sprite->dist[i])
	{
		if (game->sprite->dist[i + 1]
			&& game->sprite->dist[i] < game->sprite->dist[i + 1])
		{
			tmp = game->sprite->dist[i];
			game->sprite->dist[i] = game->sprite->dist[i + 1];
			game->sprite->dist[i + 1] = tmp;
			tmp = game->sprite->x[i];
			game->sprite->x[i] = game->sprite->x[i + 1];
			game->sprite->x[i + 1] = tmp;
			tmp = game->sprite->y[i];
			game->sprite->y[i] = game->sprite->y[i + 1];
			game->sprite->y[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	calc_sprite(t_game *game, t_raycast *rc, int i)
{
	rc->sprite_x = game->sprite->x[i] - game->player_pos_x;
	rc->sprite_y = game->sprite->y[i] - game->player_pos_y;
	rc->inv_det = 1.0 / (rc->view_x * rc->dir_y - rc->dir_x * rc->view_y);
	rc->transform_x = rc->inv_det * (rc->dir_y * rc->sprite_x
			- rc->dir_x * rc->sprite_y);
	rc->transform_y = rc->inv_det * (-rc->view_y * rc->sprite_x
			+ rc->view_x * rc->sprite_y);
	rc->sprite_screen_x = (double)((WINDOW_W / 2)
			* (1 + rc->transform_x / rc->transform_y));
	rc->v_movescreen = (double)(VMOVE / rc->transform_y);
	rc->sprite_height = fabs((double)(WINDOW_H / (rc->transform_y))) / VDIV;
	rc->drawstart_y = -rc->sprite_height / 2 + WINDOW_H / 2 + rc->v_movescreen;
	if (rc->drawstart_y < 0)
		rc->drawstart_y = 0;
	rc->drawend_y = rc->sprite_height / 2 + WINDOW_H / 2 + rc->v_movescreen;
	if (rc->drawend_y >= WINDOW_H)
		rc->drawend_y = WINDOW_H - 1;
	rc->sprite_width = fabs((double)(WINDOW_H / (rc->transform_y))) / UDIV;
	rc->drawstart_x = -rc->sprite_width / 2 + rc->sprite_screen_x;
	if (rc->drawstart_x < 0)
		rc->drawstart_x = 0;
	rc->drawend_x = rc->sprite_width / 2 + rc->sprite_screen_x;
	if (rc->drawend_x > WINDOW_W)
		rc->drawend_x = WINDOW_W;
}

void	draw_sprite(t_game *game, t_raycast *rc, double *y, int stripe)
{
	int				d;
	unsigned int	color;

	d = ((*y) - rc->v_movescreen) * 256
		- WINDOW_H * 128 + rc->sprite_height * 128;
	rc->tex_y = ((d * game->wall[6].height) / rc->sprite_height) / 256;
	if (rc->tex_y == 0)
		rc->tex_y = 1;
	color = get_pixel(game->wall[6].img, rc->tex_x, rc->tex_y);
	if ((color & 0x00FFFFFF) != 0)
		put_pixel(&game->img, stripe, (*y), color);
	(*y)++;
}

void	sprite_render(t_game *game, t_raycast *rc)
{
	int				i;
	int				stripe;
	double			y;

	i = -1;
	sprite_dist_calc(game);
	sort_sprites(game);
	i = -1;
	while (++i < game->sprite_index)
	{
		calc_sprite(game, rc, i);
		stripe = rc->drawstart_x;
		while (stripe < rc->drawend_x)
		{
			text_x_calc(game, rc, stripe);
			if (rc->transform_y > 0 && rc->transform_y < game->zbuf[stripe])
			{
				y = rc->drawstart_y;
				while (y < rc->drawend_y)
					draw_sprite(game, rc, &y, stripe);
			}
			stripe++;
		}
	}
}
