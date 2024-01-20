/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 03:02:51 by alappas           #+#    #+#             */
/*   Updated: 2024/01/19 03:03:35 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	walltype_detection(t_raycast *rc)

{
	if (rc->side == 0)
	{
		if (rc->raydir_x <= 0)
			rc->wall_type = 1;
		else
			rc->wall_type = 0;
	}
	else
	{
		if (rc->raydir_y >= 0)
			rc->wall_type = 3;
		else
			rc->wall_type = 2;
	}
}

void	step_determination(t_game *game, t_raycast *rc)

{
	if (rc->raydir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (game->player_pos_x - rc->map_x) * rc->ddx;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0 - game->player_pos_x) * rc->ddx;
	}
	if (rc->raydir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (game->player_pos_y - rc->map_y) * rc->ddy;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0 - game->player_pos_y) * rc->ddy;
	}
}

void	wallhit_detection(t_game *game, t_raycast *rc)

{
	rc->hit = 0;
	while (rc->hit == 0)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->ddx;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist_y += rc->ddy;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (game->map[rc->map_y][rc->map_x])
		{
			if (game->map[rc->map_y][rc->map_x] == '1')
				rc->hit = 1;
		}
	}
}

void	raydir_calculation(t_game *game, t_raycast *rc, int x)

{
	rc->camera_x = 2 * (double)x / (double)WINDOW_W - 1;
	rc->raydir_x = rc->dir_x + rc->camera_x * rc->view_x;
	rc->raydir_y = rc->dir_y + rc->camera_x * rc->view_y;
	rc->ddx = fabs(1 / rc->raydir_x);
	rc->ddy = fabs(1 / rc->raydir_y);
	rc->map_x = (int)game->player_pos_x;
	rc->map_y = (int)game->player_pos_y;
}

void	draw_calculation(t_raycast *rc)

{
	if (rc->side == 0)
		rc->wall_dist = rc->side_dist_x - rc->ddx;
	else
		rc->wall_dist = rc->side_dist_y - rc->ddy;
	rc->line_h = (int)(WINDOW_H / rc->wall_dist);
	rc->draw_start = -rc->line_h / 2 + WINDOW_H / 2;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	rc->draw_end = rc->line_h / 2 + WINDOW_H / 2;
	if (rc->draw_end >= WINDOW_H)
		rc->draw_end = WINDOW_H - 1;
}
