/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:33:24 by alappas           #+#    #+#             */
/*   Updated: 2024/01/20 16:48:25 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ceiling_floor(t_game *game)

{
	unsigned int	*dst;
	int				i;

	dst = (unsigned int *)game->img.addr;
	i = WINDOW_W * WINDOW_H / 2 + 1;
	while (--i > 0)
		*dst++ = game->ceiling_bit;
	i = WINDOW_W * WINDOW_H / 2 + 1;
	while (--i > 0)
		*dst++ = game->floor_bit;
}

int	error_color(char **color, int i, int *x)

{
	while (color[i][*x] && color[i][*x] != '\n')
	{
		if (!ft_isdigit(color[i][*x]))
			return (1);
		(*x)++;
	}
	return (0);
}

unsigned int	color_handle(char	*color_string)
{
	char			**tmp;
	char			**color;
	unsigned int	int_color[3];
	int				i;
	int				x;

	i = -1;
	tmp = ft_split(color_string, ' ');
	color = ft_split(tmp[1], ',');
	free_2darray(tmp);
	if (!color[0] || !color[1] || !color[2] || color[0][0] == '\n'
		|| color[1][0] == '\n' || color[2][0] == '\n')
		return (free_2darray(color), 0);
	while (color[++i] != NULL)
	{
		x = 0;
		if (error_color(color, i, &x))
			return (free_2darray(color), 0);
		int_color[i] = ft_atoi(color[i]);
	}
	free_2darray(color);
	return ((int_color[0] << 16) | (int_color[1] << 8) | int_color[2]);
}

int	main_draw(t_game *game)

{
	mlx_clear_window(game->mlx, game->win);
	bonus_c_f(game, game->raycast);
	draw_sky(game);
	ft_mouse(game);
	ft_params(game, 0);
	ft_raycast(game, game->raycast);
	sprite_render(game, game->raycast);
	keys_execute(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
