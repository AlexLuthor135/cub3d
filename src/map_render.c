/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:18:31 by alappas           #+#    #+#             */
/*   Updated: 2024/01/20 17:39:39 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_alloc(t_game *game)

{
	game->north = sprite_alloc(game, "NO ", 3);
	image_paste(game, game->north, 0);
	game->south = sprite_alloc(game, "SO ", 3);
	image_paste(game, game->south, 1);
	game->west = sprite_alloc(game, "WE ", 3);
	image_paste(game, game->west, 2);
	game->east = sprite_alloc(game, "EA ", 3);
	image_paste(game, game->east, 3);
	game->floor = sprite_alloc(game, "F ", 2);
	game->ceiling = sprite_alloc(game, "C ", 2);
	game->floor_bit = color_handle(game->floor);
	game->ceiling_bit = color_handle(game->ceiling);
	game->map = map_create(game);
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
	{
		printf("Path is missing in the file\n");
		exit_game(game);
	}
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
