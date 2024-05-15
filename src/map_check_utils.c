/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 03:43:30 by alappas           #+#    #+#             */
/*   Updated: 2024/05/15 21:37:35 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_char(char map, int i)
{
	if (i == 0)
	{
		if (ft_strchr("NEWS01", map))
			return (1);
	}
	if (i == 1)
	{
		if (ft_strchr("NEWS01 ", map))
			return (1);
	}
	if (i == 2)
	{
		if (ft_strchr("NEWS01 \n", map))
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
	if (ft_strchr("NEWS0", map[y][x]))
	{
		if (ft_strchr("NEWS", map[y][x]))
			init_player(game, x, y);
		if (y - 1 < 0 || (int)x - 1 < 0 || !map[y - 1] || !map[y + 1]
			|| ft_strlen(map[y - 1]) <= x
			|| ft_strlen(map[y + 1]) <= x
			|| !map[y][x - 1] || !map[y][x + 1]
			|| !check_char(map[y][x + 1], 0)
			|| !check_char(map[y + 1][x], 0)
			|| !check_char(map[y][x - 1], 0)
			|| !check_char(map[y - 1][x], 0))
			return (1);
	}
	return (0);
}

void	last_element(t_game *game)
{
	int	i;

	i = -1;
	while (game->map_data[++i])
	{
		if (!ft_strncmp(game->map_data[i], "C", 1))
			game->l_el = "C";
		else if (!ft_strncmp(game->map_data[i], "F", 1))
			game->l_el = "F";
		else if (!ft_strncmp(game->map_data[i], "NO", 2))
			game->l_el = "NO";
		else if (!ft_strncmp(game->map_data[i], "SO", 2))
			game->l_el = "SO";
		else if (!ft_strncmp(game->map_data[i], "EA", 2))
			game->l_el = "EA";
		else if (!ft_strncmp(game->map_data[i], "WE", 2))
			game->l_el = "WE";
		index_string_helper(game, i);
	}
}

int	error_string_helper(char **map, int i)

{
	if (ft_strncmp(map[i], "NO ", 3) && ft_strncmp(map[i], "SO ", 3)
		&& ft_strncmp(map[i], "WE ", 3) && ft_strncmp(map[i], "EA ", 3)
		&& ft_strncmp(map[i], "F ", 2) && ft_strncmp(map[i], "C ", 2)
		&& ft_strncmp(map[i], "\n", 1))
		return (1);
	return (0);
}
