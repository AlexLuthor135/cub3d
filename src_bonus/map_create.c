/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:54:26 by alappas           #+#    #+#             */
/*   Updated: 2024/02/06 07:10:17 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	find_map(char **map, int *i)
{
	int	x;

	x = 0;
	while (map[*i])
	{
		x = 0;
		while (map[*i][x])
		{
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
	while (game->map_data[i++]
		&& ft_strncmp(game->map_data[i], game->l_el, ft_strlen(game->l_el)))
		continue ;
	i++;
	find_map(game->map_data, &i);
	map = ft_calloc((sizeof(char *)) * (game->map_height - i), 1);
	while (game->map_data[i])
		map[j++] = ft_strdup(game->map_data[i++]);
	map[j] = NULL;
	return (map);
}
