/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:21:16 by alappas           #+#    #+#             */
/*   Updated: 2024/01/20 17:38:24 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	put_mini_pixel(t_game *game, t_game point, int color)

{
	int	rect_size;
	int	rect_x;
	int	rect_y;
	int	i;
	int	j;

	rect_size = 5;
	rect_x = point.x * rect_size;
	rect_y = point.y * rect_size;
	i = 0;
	while (i < rect_size)
	{
		j = 0;
		while (j < rect_size)
		{
			put_pixel(&game->img, rect_x + i, rect_y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_screen(t_game *game)
{
	t_game	point;

	ft_bzero(&point, sizeof(t_game));
	while (game->map[point.y])
	{
		point.x = 0;
		while (game->map[point.y][point.x])
		{
			if (game->map[point.y][point.x] == '1')
				put_mini_pixel(game, point, 0xFFFFFF);
			else if (game->map[point.y][point.x] == 'D')
				put_mini_pixel(game, point, 0x0000FF);
			else if (game->map[point.y][point.x] == '0'
				|| ft_strchr("NEWS2", game->map[point.y][point.x]))
				put_mini_pixel(game, point, 0x000000);
			point.x++;
		}
		point.y++;
	}
}

void	draw_void(t_game *game)
{
	int	rect_size;
	int	rect_x;
	int	rect_y;
	int	i;
	int	j;

	rect_size = 5;
	rect_x = game->player_pos_x * rect_size;
	rect_y = game->player_pos_y * rect_size;
	i = 0;
	while (i < rect_size)
	{
		j = 0;
		while (j < rect_size)
		{
			put_pixel(&game->img, rect_x + i, rect_y + j, 0x000000);
			j++;
		}
		i++;
	}
}

void	draw_hero(t_game *game)
{
	int	rect_size;
	int	rect_x;
	int	rect_y;
	int	i;
	int	j;

	rect_size = 5;
	rect_x = game->player_pos_x * rect_size;
	rect_y = game->player_pos_y * rect_size;
	i = 0;
	while (i < rect_size)
	{
		j = 0;
		while (j < rect_size)
		{
			put_pixel(&game->img, rect_x + i, rect_y + j, 0xFF0000);
			j++;
		}
		i++;
	}
}
