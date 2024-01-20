/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 02:39:22 by alappas           #+#    #+#             */
/*   Updated: 2024/01/19 03:06:50 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	texture_assign(t_game *game, t_raycast *rc)
{
	double	wall_hit;

	if (rc->side == 0)
		wall_hit = game->player_pos_y + rc->wall_dist * rc->raydir_y;
	else
		wall_hit = game->player_pos_x + rc->wall_dist * rc->raydir_x;
	wall_hit -= floor(wall_hit);
	rc->texture_x = (int)(wall_hit * (double)(game->wall[rc->wall_type].width));
	rc->texture_step = 1.0 * game->wall[rc->wall_type].height / rc->line_h;
	rc->texture_pos = (rc->draw_start - WINDOW_H / 2
			+ rc->line_h / 2) * rc->texture_step;
}

void	draw_walls(t_game *game, t_raycast *rc, int x, int y)

{
	rc->texture_pos += rc->texture_step;
	rc->texture_y = (int)rc->texture_pos
		& (game->wall[rc->wall_type].height - 1);
	rc->color = get_pixel(game->wall[rc->wall_type].img,
			rc->texture_x, rc->texture_y);
	put_pixel(&game->img, x, y, rc->color);
}

void	ft_raycast(t_game *game, t_raycast *rc)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WINDOW_W)
	{
		raydir_calculation(game, rc, x);
		step_determination(game, rc);
		wallhit_detection(game, rc);
		draw_calculation(rc);
		walltype_detection(rc);
		texture_assign(game, rc);
		y = rc->draw_start;
		while (y <= rc->draw_end)
		{
			draw_walls(game, rc, x, y);
			y++;
		}
	}
}
