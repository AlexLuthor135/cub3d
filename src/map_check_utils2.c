/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 04:32:45 by alappas           #+#    #+#             */
/*   Updated: 2024/02/06 04:43:29 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	index_string_error(t_game *game)
{
	if (game->s_index.ceiling > 1 || game->s_index.floor > 1
		|| game->s_index.north > 1 || game->s_index.south > 1
		|| game->s_index.east > 1 || game->s_index.west > 1)
	{
		printf("Error: Duplicating map elements\n");
		exit_game(game);
	}
}

void	index_string_helper(t_game *game, int i)
{
	if (!ft_strncmp(game->map_data[i], "C", 1))
		game->s_index.ceiling++;
	if (!ft_strncmp(game->map_data[i], "F", 1))
		game->s_index.floor++;
	if (!ft_strncmp(game->map_data[i], "NO", 2))
		game->s_index.north++;
	if (!ft_strncmp(game->map_data[i], "SO", 2))
		game->s_index.south++;
	if (!ft_strncmp(game->map_data[i], "EA", 2))
		game->s_index.east++;
	if (!ft_strncmp(game->map_data[i], "WE", 2))
		game->s_index.west++;
	index_string_error(game);
}
