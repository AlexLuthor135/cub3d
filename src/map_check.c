/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:47:58 by alappas           #+#    #+#             */
/*   Updated: 2024/01/19 18:07:48 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	error_string(t_game *game)
{
	char	**map;
	int		i;
	int		x;

	map = game->map_data;
	i = 0;
	while (map[i] && ft_strncmp(map[i], "C ", 2))
	{
		x = 0;
		if (map[i][0] == ' ' || map[i][0] == '\n')
		{
			while (map[i][x] && map[i][x] != '\n')
			{
				if (map[i][x] != ' ' || map[i][x] != '\t')
					return (1);
				x++;
			}
		}
		else if (ft_strncmp(map[i], "NO ", 3) && ft_strncmp(map[i], "SO ", 3)
			&& ft_strncmp(map[i], "WE ", 3) && ft_strncmp(map[i], "EA ", 3)
			&& ft_strncmp(map[i], "F ", 2) && ft_strncmp(map[i], "C ", 2))
			return (1);
		i++;
	}
	return (0);
}

int	error_symbols(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	x = 0;
	y = 0;
	map = game->map;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (!check_char(map[y][x], 1))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	error_corners(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = game->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NEWS0", game->map[y][x]))
			{
				if (!check_char(map[y - 1][x - 1], 0)
					|| !check_char(map[y + 1][x - 1], 0) || (!map[y - 1][x + 1]
					|| !check_char(map[y - 1][x + 1], 0))
					|| !check_char(map[y + 1][x + 1], 0))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	error_walls(t_game *game)
{
	size_t	x;
	int		y;
	char	**map;

	y = -1;
	map = game->map;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (error_walls_helper(game, x, y))
				return (1);
		}
	}
	return (0);
}

int	map_check(t_game *game)
{
	if (error_symbols(game))
		return (printf("Error: Wrong map symbols\n"), 1);
	if (!game->north || !game->south || !game->east || !game->west)
		return (printf("Error: Missing cardinal directions\n"), 1);
	if (!game->floor || !game->ceiling
		|| !game->floor_bit || !game->ceiling_bit)
		return (printf("Error: Missing floor/ceiling\n"), 1);
	if (error_walls(game))
		return (printf("Error: Empty space exists\n"), 1);
	if (error_corners(game))
		return (printf("Error: Empty corner exists\n"), 1);
	if (game->player_index != 1)
		return (printf("Error: Wrong player position\n"), 1);
	return (0);
}
