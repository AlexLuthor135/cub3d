/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:10:01 by alappas           #+#    #+#             */
/*   Updated: 2024/01/20 15:47:19 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	map_fix(t_game *game)

{
	int	x;
	int	y;

	y = -1;
	while (game->map_data[++y])
	{
		x = -1;
		while (game->map_data[y][++x])
		{
			if (game->map_data[y][x] == '\t')
				game->map_data[y][x] = ' ';
		}
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (printf("Error: Wrong amount of arguments\n"), 0);
	if (check_ext(argv[1]) == 1)
		return (0);
	game = ft_calloc(sizeof(t_game), 1);
	game->raycast = ft_calloc(sizeof(t_raycast), 1);
	game->map_data = map_render(game, argv[1]);
	map_fix(game);
	if (error_string(game))
		return (printf("Error: Wrong map element\n"), exit_game(game));
	game->map = map_create(game);
	if (map_check(game))
		exit_game(game);
	map_alloc(game);
	music(game);
	init_sprite(game);
	init_facing_direction(game);
	mlx_skip(game);
	return (0);
}

int	check_ext(char *s2)
{
	char	*s1;
	int		i;
	int		j;

	s1 = ".cub";
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	while (i >= 0)
	{
		if (s1[i--] == s2[j--])
			continue ;
		else
			return (printf("Error: Wrong map extension\n"), 1);
	}
	return (0);
}

int	exit_game(t_game *game)
{
	kill(game->pid + 1, SIGTERM);
	exit(0);
	return (0);
}
