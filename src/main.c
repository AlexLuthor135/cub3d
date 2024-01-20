/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:10:01 by alappas           #+#    #+#             */
/*   Updated: 2024/01/20 17:40:06 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	mlx_func(t_game *game)

{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_W,
			WINDOW_H, "Golden Sun");
	game->img.img = mlx_new_image(game->mlx, WINDOW_W, WINDOW_H);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	mlx_loop_hook(game->mlx, main_draw, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 1L << 0, exit_game, game);
	mlx_loop(game->mlx);
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
	map_alloc(game);
	if (map_check(game))
		exit_game(game);
	init_facing_direction(game);
	mlx_func(game);
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
	(void)game;
	exit(0);
	return (0);
}
