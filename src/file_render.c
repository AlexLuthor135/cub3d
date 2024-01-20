/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:28:13 by alappas           #+#    #+#             */
/*   Updated: 2024/01/20 17:39:28 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	image_error(t_game *game, char *full_path, int i)

{
	if (i == 0)
		printf("Error: Proper path is missing\n");
	else if (i == 1)
		printf("Error: Image allocation failed\n");
	if (full_path)
		free(full_path);
	exit_game(game);
}

void	image_paste(t_game *game, char *path, int i)

{
	t_wall	*wall;
	char	*full_path;

	full_path = file_render(path);
	if (!path || !full_path)
		image_error(game, full_path, 0);
	wall = &game->wall[i];
	wall->img = malloc(sizeof(t_img));
	wall->img->img = mlx_xpm_file_to_image(&game->mlx, full_path,
			&wall->width, &wall->height);
	if (!wall->img->img)
		image_error(game, full_path, 1);
	wall->img->addr = mlx_get_data_addr(wall->img->img,
			&wall->img->bits_per_pixel, &wall->img->line_length,
			&wall->img->endian);
	free(full_path);
}

char	*ft_strdup2(const char *s1)

{
	char	*array;
	int		i;

	i = 0;
	array = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!array)
		return (NULL);
	while (*s1 && *s1 != '\n')
		array[i++] = *s1++;
	array[i] = '\0';
	return (array);
}

char	*file_render(char *path)
{
	char	**tmp;
	char	*full_path;

	tmp = NULL;
	if (!path)
		return (NULL);
	else
		tmp = ft_split(path, ' ');
	if (tmp[1])
	{
		full_path = ft_strdup2(tmp[1]);
		free(path);
		free_2darray(tmp);
		return (full_path);
	}
	if (path)
		free(path);
	return (NULL);
}
