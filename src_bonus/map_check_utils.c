/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 03:43:30 by alappas           #+#    #+#             */
/*   Updated: 2024/01/20 16:17:43 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_char(char map, int i)
{
	if (i == 0)
	{
		if (ft_strchr("NEWS012D", map))
			return (1);
	}
	if (i == 1)
	{
		if (ft_strchr("NEWS012D ", map))
			return (1);
	}
	if (i == 2)
	{
		if (ft_strchr("NEWS012D \n", map))
			return (1);
	}
	return (0);
}

void	init_player(t_game *game, int x, int y)
{
	game->direction = game->map[y][x];
	game->player_index++;
	game->player_pos_x = x + 0.5;
	game->player_pos_y = y + 0.5;
}

int	error_walls_helper(t_game *game, size_t x, int y)
{
	char	**map;

	map = game->map;
	if (ft_strchr("NEWS02D", game->map[y][x]))
	{
		if (ft_strchr("NEWS", game->map[y][x]))
			init_player(game, x, y);
		if (game->map[y][x] == '2')
			game->sprite_index++;
		if (game->map[y][x] == 'D')
			game->door_index++;
		if (y - 1 < 0 || (int)x - 1 < 0 || !map[y - 1] || !map[y + 1]
			|| ft_strlen(map[y - 1]) <= x
			|| !map[y][x - 1] || !map[y][x + 1]
			|| !check_char(map[y][x + 1], 0)
			|| !check_char(map[y + 1][x], 0)
			|| !check_char(map[y][x - 1], 0)
			|| !check_char(map[y - 1][x], 0))
			return (1);
	}
	return (0);
}

int	sprite_check(t_game *game)

{
	if (!game->north || !game->south || !game->east || !game->west)
		return (printf("Error: Missing cardinal directions\n"), 1);
	if (!game->floor || !game->ceiling)
		return (printf("Error: Missing floor/ceiling\n"), 1);
	return (0);
}

int	error_string_helper(char **map, int i)

{
	if (ft_strncmp(map[i], "NO ", 3) && ft_strncmp(map[i], "SO ", 3)
		&& ft_strncmp(map[i], "WE ", 3) && ft_strncmp(map[i], "EA ", 3)
		&& ft_strncmp(map[i], "F ", 2) && ft_strncmp(map[i], "C ", 2)
		&& ft_strncmp(map[i], "S ", 2) && ft_strncmp(map[i], "M ", 2)
		&& ft_strncmp(map[i], "D ", 2))
		return (1);
	return (0);
}
