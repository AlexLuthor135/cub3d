/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:47:58 by alappas           #+#    #+#             */
/*   Updated: 2024/05/15 21:38:05 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	error_string(t_game *game)
{
	char	**map;
	int		i;
	int		x;

	map = game->map_data;
	i = 0;
	while (map[i])
	{
		x = 0;
		if (map[i][0] == '\0' || map[i][0] == ' ')
		{
			while (map[i][x] && map[i][x] != '\0')
			{
				if (map[i][x] != ' ' && map[i][x] != '\t')
					return (1);
				x++;
			}
		}
		else if (error_string_helper(map, i))
			return (1);
		if (!ft_strncmp(map[i], game->l_el, ft_strlen(game->l_el)))
			break ;
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
		while (map[y][x] && map[y][x] != '\0')
		{
			if (!check_char(map[y][x], 2))
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
			if (ft_strchr("NEWS02D", map[y][x]))
			{
				if (!map[y - 1][x + 1] || !map[y + 1][x + 1]
					||!check_char(map[y - 1][x - 1], 0)
					|| !check_char(map[y + 1][x - 1], 0)
					|| !check_char(map[y - 1][x + 1], 0)
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
			if (error_walls_helper(game, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	map_check(t_game *game)
{
	if (error_symbols(game))
		return (printf("Error: Wrong map symbols\n"), 1);
	if (error_walls(game))
		return (printf("Error: Empty space exists\n"), 1);
	if (error_corners(game))
		return (printf("Error: Empty corner exist\n"), 1);
	if (game->player_index != 1)
		return (printf("Error: Wrong player position\n"), 1);
	return (0);
}
