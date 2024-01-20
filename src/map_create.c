/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:54:26 by alappas           #+#    #+#             */
/*   Updated: 2024/01/19 21:14:59 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_map(t_game *game, char **map, int *i)
{
	int	x;

	x = 0;
	while (map[*i])
	{
		x = 0;
		while (map[*i][x])
		{
			if (!check_char(map[*i][x], 2))
			{
				printf("Error: Wrong map symbols\n");
				exit_game(game);
			}
			if (check_char(map[*i][x], 0))
				return ;
			x++;
		}
		(*i)++;
	}
}

char	**map_create(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	i = 0;
	map = NULL;
	while (game->map_data[i++] && ft_strncmp(game->map_data[i], "C", 1))
		continue ;
	i++;
	find_map(game, game->map_data, &i);
	map = ft_calloc((sizeof(char *)) * (game->map_height - i), 1);
	while (game->map_data[i])
	{
		map[j] = ft_strdup(game->map_data[i]);
		i++;
		j++;
	}
	map[j] = NULL;
	return (map);
}
