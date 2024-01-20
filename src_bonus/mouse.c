/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:07:10 by alappas           #+#    #+#             */
/*   Updated: 2024/01/20 17:07:11 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_mouse(t_game *game)
{
	int	x;
	int	y;
	int	dx;

	mlx_mouse_hide();
	mlx_mouse_get_pos(game->win, &x, &y);
	dx = x - WINDOW_W / 2;
	if (dx > 0)
		ft_params(game, dx * (-(2 * M_PI / 11520)));
	else if (dx < 0)
		ft_params(game, -dx * 2 * M_PI / 11520);
	mlx_mouse_move(game->win, WINDOW_W / 2, WINDOW_H / 2);
	return (0);
}

void	ft_direction(t_raycast *pl, double rotate)
{
	double	old_direction_x;

	old_direction_x = pl->dir_x;
	pl->dir_x = pl->dir_x * cos(rotate) - pl->dir_y * sin(rotate);
	pl->dir_y = old_direction_x * sin(rotate) + pl->dir_y * cos(rotate);
}

void	ft_view(t_raycast *pl, double rotate)
{
	double	old_plane_x;

	old_plane_x = pl->view_x;
	pl->view_x = pl->view_x * cos(rotate) - pl->view_y * sin(rotate);
	pl->view_y = old_plane_x * sin(rotate) + pl->view_y * cos(rotate);
}

void	ft_params(t_game *game, double rotate)
{
	ft_direction(game->raycast, rotate);
	ft_view(game->raycast, rotate);
}
