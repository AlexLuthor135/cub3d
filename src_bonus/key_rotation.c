/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:01:10 by alappas           #+#    #+#             */
/*   Updated: 2024/01/20 17:01:12 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	rotate_left(t_game *game, double old_direction_x, double old_plane_x)
{
	game->raycast->dir_x = game->raycast->dir_x * cos(ROTATION_SPEED)
		- game->raycast->dir_y * sin(ROTATION_SPEED);
	game->raycast->dir_y = old_direction_x * sin(ROTATION_SPEED)
		+ game->raycast->dir_y * cos(ROTATION_SPEED);
	game->raycast->view_x = game->raycast->view_x * cos(ROTATION_SPEED)
		- game->raycast->view_y * sin(ROTATION_SPEED);
	game->raycast->view_y = old_plane_x * sin(ROTATION_SPEED)
		+ game->raycast->view_y * cos(ROTATION_SPEED);
}

void	rotate_right(t_game *game, double old_direction_x, double old_plane_x)
{
	game->raycast->dir_x = game->raycast->dir_x * cos(-ROTATION_SPEED)
		- game->raycast->dir_y * sin(-ROTATION_SPEED);
	game->raycast->dir_y = old_direction_x * sin(-ROTATION_SPEED)
		+ game->raycast->dir_y * cos(-ROTATION_SPEED);
	game->raycast->view_x = game->raycast->view_x * cos(-ROTATION_SPEED)
		- game->raycast->view_y * sin(-ROTATION_SPEED);
	game->raycast->view_y = old_plane_x * sin(-ROTATION_SPEED)
		+ game->raycast->view_y * cos(-ROTATION_SPEED);
}

void	rotate_camera(t_game *game, int key)
{
	double	old_plane_x;
	double	old_direction_x;

	old_direction_x = game->raycast->dir_x;
	old_plane_x = game->raycast->view_x;
	if (key == LEFT_KEY && game->key_right)
		rotate_left(game, old_direction_x, old_plane_x);
	else if (key == RIGHT_KEY)
		rotate_right(game, old_direction_x, old_plane_x);
}
