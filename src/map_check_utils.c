/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 03:43:30 by alappas           #+#    #+#             */
/*   Updated: 2024/01/19 03:45:14 by alappas          ###   ########.fr       */
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
	if (ft_strchr("NEWS0", game->map[y][x]))
	{
		if (ft_strchr("NEWS", game->map[y][x]))
			init_player(game, x, y);
		if (y - 1 < 0 || x - 1 < 0 || !map[y - 1] || !map[y + 1]
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
