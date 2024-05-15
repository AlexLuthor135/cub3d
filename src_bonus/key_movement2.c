/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movement2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:06:58 by alappas           #+#    #+#             */
/*   Updated: 2024/05/15 21:46:12 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		game->key_esc = 1;
	if (key == KEY_S)
		game->key_s = 1;
	if (key == KEY_W)
		game->key_w = 1;
	if (key == KEY_A)
		game->key_a = 1;
	if (key == KEY_D)
		game->key_d = 1;
	if (key == KEY_LEFT && game->key_right == 0)
		game->key_left = 1;
	if (key == KEY_RIGHT && game->key_left == 0)
		game->key_right = 1;
	if (key == KEY_E)
		game->key_e = 1;
	if (key == KEY_Q)
		game->key_q = 1;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == KEY_ESC)
		game->key_esc = 0;
	if (key == KEY_S)
		game->key_s = 0;
	if (key == KEY_W)
		game->key_w = 0;
	if (key == KEY_A)
		game->key_a = 0;
	if (key == KEY_D)
		game->key_d = 0;
	if (key == KEY_LEFT)
		game->key_left = 0;
	if (key == KEY_RIGHT)
		game->key_right = 0;
	if (key == KEY_E)
		game->key_e = 0;
	if (key == KEY_Q)
		game->key_q = 0;
	return (0);
}

int	keys_execute(t_game *game)
{
	double	old_plane_x;
	double	old_direction_x;

	old_direction_x = game->raycast->dir_x;
	old_plane_x = game->raycast->view_x;
	if (game->key_esc)
		exit_game(game);
	if (game->key_w)
		front_move(game);
	if (game->key_s)
		back_move(game);
	if (game->key_a)
		left_move(game);
	if (game->key_d)
		right_move(game);
	if (game->key_left)
		rotate_left(game, old_direction_x, old_plane_x);
	if (game->key_right)
		rotate_right(game, old_direction_x, old_plane_x);
	draw_screen(game);
	draw_hero(game);
	return (0);
}

int	key_movement(int key, t_game *game)
{
	if (key == game->key_esc)
		exit_game(game);
	if (key == game->key_w)
		front_move(game);
	if (key == game->key_s)
		back_move(game);
	if (key == game->key_a)
		left_move(game);
	if (key == game->key_d)
		right_move(game);
	if (key == KEY_LEFT || key == KEY_RIGHT)
		rotate_camera(game, key);
	return (0);
}
