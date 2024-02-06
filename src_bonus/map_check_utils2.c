/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 03:31:08 by alappas           #+#    #+#             */
/*   Updated: 2024/02/06 04:51:48 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	last_element_bonus(t_game *game, int i)
{
	if (!ft_strncmp(game->map_data[i], "M", 1))
		game->l_el = "M";
	else if (!ft_strncmp(game->map_data[i], "D", 1))
		game->l_el = "D";
	else if (!ft_strncmp(game->map_data[i], "S2", 2))
		game->l_el = "S2";
	else if (!ft_strncmp(game->map_data[i], "S1", 2))
		game->l_el = "S1";
}

void	last_element(t_game *game)
{
	int	i;

	i = -1;
	while (game->map_data[++i])
	{
		if (!ft_strncmp(game->map_data[i], "C", 1))
			game->l_el = "C";
		else if (!ft_strncmp(game->map_data[i], "F", 1))
			game->l_el = "F";
		else if (!ft_strncmp(game->map_data[i], "NO", 2))
			game->l_el = "NO";
		else if (!ft_strncmp(game->map_data[i], "SO", 2))
			game->l_el = "SO";
		else if (!ft_strncmp(game->map_data[i], "EA", 2))
			game->l_el = "EA";
		else if (!ft_strncmp(game->map_data[i], "WE", 2))
			game->l_el = "WE";
		else
			last_element_bonus(game, i);
		index_string_helper(game, i);
	}
}

void	index_string_error(t_game *game)
{
	if (game->s_index.ceiling > 1 || game->s_index.floor > 1
		|| game->s_index.north > 1 || game->s_index.south > 1
		|| game->s_index.east > 1 || game->s_index.west > 1
		|| game->s_index.door > 1 || game->s_index.sprite1 > 1
		|| game->s_index.sprite2 > 1 || game->s_index.music > 1)
	{
		printf("Error: Duplicating map elements\n");
		exit_game(game);
	}
}

void	index_string_helper_bonus(t_game *game, int i)
{
	if (!ft_strncmp(game->map_data[i], "M", 1))
		game->s_index.music++;
	if (!ft_strncmp(game->map_data[i], "D", 1))
		game->s_index.door++;
	if (!ft_strncmp(game->map_data[i], "S1", 2))
		game->s_index.sprite1++;
	if (!ft_strncmp(game->map_data[i], "S2", 2))
		game->s_index.sprite2++;
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
	index_string_helper_bonus(game, i);
	index_string_error(game);
}
