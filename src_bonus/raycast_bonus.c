/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:06:26 by alappas           #+#    #+#             */
/*   Updated: 2024/01/20 06:02:54 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_c_f(t_game *game, t_raycast *rc, int x, int y)
{
	int			tx_floor;
	int			ty_floor;
	int			tx_ceiling;
	int			ty_ceiling;
	uint32_t	color;

	rc->cell_x = (int)(rc->floor_x);
	rc->cell_y = (int)(rc->floor_y);
	tx_floor = (int)(game->wall[4].width * (rc->floor_x - rc->cell_x))
		& (game->wall->width - 1);
	ty_floor = (int)(game->wall[4].height * (rc->floor_y - rc->cell_y))
		& (game->wall->height - 1);
	tx_ceiling = (int)(game->wall[5].width * (rc->floor_x - rc->cell_x))
		& (game->wall->width - 1);
	ty_ceiling = (int)(game->wall[5].height * (rc->floor_y - rc->cell_y))
		& (game->wall->height - 1);
	rc->floor_x += rc->floorstep_x;
	rc->floor_y += rc->floorstep_y;
	color = get_pixel(game->wall[4].img, tx_floor, ty_floor);
	put_pixel(&game->img, x, y, color);
}
	//if you want to draw a ceiling, move these lines below line 36
	//and comment draw_sky in image_render.c
	// color = get_pixel(game->wall[5].img, tx_ceiling, ty_ceiling);
	// put_pixel(&game->img, x, (WINDOW_H - y - 1), color);

void	calc_c_f(t_game *game, t_raycast *rc, int y)
{
	rc->raydir_x0 = rc->dir_x - rc->view_x;
	rc->raydir_y0 = rc->dir_y - rc->view_y;
	rc->raydir_x1 = rc->dir_x + rc->view_x;
	rc->raydir_y1 = rc->dir_y + rc->view_y;
	rc->cf_height = y - WINDOW_H / 2;
	rc->pos_z = 0.5 * WINDOW_H;
	rc->row_distance = rc->pos_z / rc->cf_height;
	rc->floorstep_x = rc->row_distance
		* (rc->raydir_x1 - rc->raydir_x0) / WINDOW_W;
	rc->floorstep_y = rc->row_distance
		* (rc->raydir_y1 - rc->raydir_y0) / WINDOW_W;
	rc->floor_x = game->player_pos_x + rc->row_distance * rc->raydir_x0;
	rc->floor_y = game->player_pos_y + rc->row_distance * rc->raydir_y0;
}

void	bonus_c_f(t_game *game, t_raycast *rc)
{
	int	y;
	int	x;

	y = -1;
	while (++y < WINDOW_H)
	{
		calc_c_f(game, rc, y);
		x = -1;
		while (++x < WINDOW_W)
			draw_c_f(game, rc, x, y);
	}
}
