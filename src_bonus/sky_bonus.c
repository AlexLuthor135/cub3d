/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:50:14 by alappas           #+#    #+#             */
/*   Updated: 2024/01/20 18:40:51 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	sky_init(t_game *game, t_raycast *rc, int x)
{
	rc->sky_horizon = (WINDOW_H / 2.0) + 100;
	if (rc->sky_horizon < 0 || rc->sky_horizon >= WINDOW_H)
	{
		if (rc->sky_horizon < 0)
			rc->sky_horizon = 0;
		else
			rc->sky_horizon = WINDOW_H - 1;
	}
	rc->sky_ratio_x = ((double)game->wall[5].width / 8.0) / ((double)WINDOW_W);
	rc->sky_orientation = (atan2(rc->dir_x, rc->dir_y) / M_PI) / 2;
	if (rc->sky_orientation < 0)
		rc->sky_orientation = 1.0 + rc->sky_orientation;
	rc->sky_ratio_y = ((double)game->wall[5].height / 2.0) / ((double)WINDOW_H);
	rc->sky_coord_x = (x * rc->sky_ratio_x)
		+ (rc->sky_orientation * (game->wall[5].width - 1));
	if (rc->sky_coord_x < 0)
		rc->sky_coord_x = 0;
	if (rc->sky_coord_x >= game->wall[5].width)
		rc->sky_coord_x -= game->wall[5].width - 1;
}

void	draw_sky(t_game *game)
{
	int			x;
	int			y;
	t_raycast	*rc;
	uint32_t	color;

	rc = game->raycast;
	x = -1;
	while (++x < WINDOW_W)
	{
		sky_init(game, rc, x);
		y = WINDOW_H;
		while (--y >= WINDOW_H / 2)
		{
			rc->sky_offset_y = WINDOW_H - rc->sky_horizon + y;
			rc->sky_coord_y = (double)rc->sky_offset_y * rc->sky_ratio_y;
			if (rc->sky_coord_y >= 0 && rc->sky_coord_y < game->wall[5].height)
			{
				color = get_pixel(game->wall[5].img,
						rc->sky_coord_x, rc->sky_coord_y);
				if ((color & 0x00FFFFFF) != 0)
					put_pixel(&game->img, x, (WINDOW_H - y - 1), color);
			}
		}
	}
}
