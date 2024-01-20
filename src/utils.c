/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:18:05 by alappas           #+#    #+#             */
/*   Updated: 2024/01/20 19:14:30 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_strdel(char **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
}

void	free_2darray(char **array)
{
	int	i;

	i = -1;
	if (!array)
		return ;
	while (array[++i])
		ft_strdel(&array[i]);
	free(array);
	array = NULL;
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	init_facing_direction(t_game *game)
{
	if (game->direction == 'W')
	{
		game->raycast->dir_x = -1;
		game->raycast->view_y = 0.66;
	}
	if (game->direction == 'S')
	{
		game->raycast->dir_y = -1;
		game->raycast->view_x = -0.66;
	}
	if (game->direction == 'E')
	{
		game->raycast->dir_x = 1;
		game->raycast->view_y = -0.66;
	}
	if (game->direction == 'N')
	{
		game->raycast->dir_y = 1;
		game->raycast->view_x = 0.66;
	}
}
