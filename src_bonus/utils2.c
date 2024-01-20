/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:07:29 by alappas           #+#    #+#             */
/*   Updated: 2024/01/20 19:15:12 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	music(t_game *game)
{
	char	*music_path;
	char	*full_path;

	music_path = file_render(game->music);
	if (music_path)
	{
		game->pid = -1;
		game->pid = fork();
		full_path = ft_strjoin("afplay ", music_path);
		if (game->pid == 0)
		{
			system(full_path);
			kill(game->pid + 1, SIGTERM);
			exit(EXIT_FAILURE);
		}
		free(full_path);
	}
	if (music_path)
		free(music_path);
}

void	mlx_skip(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_W, WINDOW_H, "Golden Sun");
	game->img.img = mlx_new_image(game->mlx, WINDOW_W, WINDOW_H);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	mlx_loop_hook(game->mlx, main_draw, game);
	sprite_locate(game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 1L << 0, exit_game, game);
	mlx_loop(game->mlx);
}

void	init_facing_direction(t_game *game)
{
	if (game->direction == 'W')
	{
		game->raycast->dir_x = -1;
		game->raycast->view_y = 0.66;
	}
	if (game->direction == 'S')
	{
		game->raycast->dir_y = -1;
		game->raycast->view_x = -0.66;
	}
	if (game->direction == 'E')
	{
		game->raycast->dir_x = 1;
		game->raycast->view_y = -0.66;
	}
	if (game->direction == 'N')
	{
		game->raycast->dir_y = 1;
		game->raycast->view_x = 0.66;
	}
}

void	init_sprite(t_game *game)

{
	game->sprite = ft_calloc(sizeof(t_sprite), 1);
	game->sprite->x = ft_calloc(sizeof(double), game->sprite_index + 1);
	game->sprite->y = ft_calloc(sizeof(double), game->sprite_index + 1);
	game->sprite->dist = ft_calloc(sizeof(double), game->sprite_index + 1);
}

void	sprite_parse(t_game *game)
{
	game->north = sprite_alloc(game, "NO ", 3);
	game->south = sprite_alloc(game, "SO ", 3);
	game->west = sprite_alloc(game, "WE ", 3);
	game->east = sprite_alloc(game, "EA ", 3);
	game->floor = sprite_alloc(game, "F ", 2);
	game->ceiling = sprite_alloc(game, "C ", 2);
	game->barrel = sprite_alloc(game, "S ", 2);
	game->music = sprite_alloc(game, "M ", 2);
	game->door = sprite_alloc(game, "D ", 2);
	if (game->barrel == NULL && game->sprite_index > 0)
	{
		printf("Error: Sprite path missing, remove the sprites from the map\n");
		exit_game(game);
	}
	if (game->door == NULL && game->door_index > 0)
	{
		printf("Error: Door path missing, remove doors from the map\n");
		exit_game(game);
	}
}
