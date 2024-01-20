/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:18:31 by alappas           #+#    #+#             */
/*   Updated: 2024/01/20 17:39:45 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	map_alloc(t_game *game)

{
	int	i;

	i = -1;
	sprite_parse(game);
	image_paste(game, game->north, ++i);
	image_paste(game, game->south, ++i);
	image_paste(game, game->west, ++i);
	image_paste(game, game->east, ++i);
	image_paste(game, game->floor, ++i);
	image_paste(game, game->ceiling, ++i);
	if (game->barrel != NULL && game->sprite_index > 0)
		image_paste(game, game->barrel, ++i);
	if (game->door != NULL && game->door_index > 0)
	{
		image_paste(game, game->door, ++i);
		game->raycast->door_i = i;
	}
}

char	*sprite_alloc(t_game *game, char *str, int len)
{
	char	**map;
	int		i;

	map = game->map_data;
	i = 0;
	while (map[i] && ft_strncmp(map[i], str, len))
		i++;
	if (!map[i])
		return (NULL);
	return (ft_strdup(map[i]));
}

int	count_y(int fd)

{
	int		i;
	char	*s;

	i = 1;
	s = get_next_line(fd);
	while (s)
	{
		free(s);
		s = get_next_line(fd);
		i++;
	}
	free(s);
	return (i);
}

void	error_fd(t_game *game)

{
	printf("Error: Invalid read\n");
	exit_game(game);
}

char	**map_render(t_game *game, char *map)


{
	int		fd;
	char	**world;
	char	*str;
	int		i;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_fd(game);
	game->map_height = (count_y(fd));
	world = ft_calloc((sizeof(char *)) * (game->map_height + 1), 1);
	if (!world)
		return (NULL);
	close(fd);
	i = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		world[i++] = str;
		str = get_next_line(fd);
	}
	close(fd);
	world[i] = NULL;
	return (world);
}
