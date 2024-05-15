/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 23:57:16 by alappas           #+#    #+#             */
/*   Updated: 2024/05/16 00:06:04 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

#ifdef __linux__

void	stop_music(void)
{
	char	cwd_path[1024];
	char	*full_path;
	int		pid;
	FILE	*f;

	pid = 0;
	full_path = ft_strjoin(getcwd(cwd_path, sizeof(cwd_path)), "/pid.txt");
	f = fopen(full_path, "r");
	if (f == NULL)
	{
		printf("Error opening file\n");
		if (full_path)
			free(full_path);
		return ;
	}
	fscanf(f, "%d", &pid);
	fclose(f);
	if (kill(pid, SIGKILL) == -1)
		printf("Error: music not stopped\n");
	remove(full_path);
	if (full_path)
		free(full_path);
}

void	music(t_game *game)
{
	char	*music_path;
	char	*full_path;

	music_path = file_render(game->music);
	if (music_path)
	{
		game->music = dirname(strdup(music_path));
		game->pid = -1;
		game->pid = fork();
		full_path = ft_strjoin(MUSIC, music_path);
		if (game->pid == 0)
		{
			system(full_path);
			kill(game->pid + 1, SIGTERM);
			exit(EXIT_FAILURE);
		}
		free(full_path);
	}
	if (music_path)
		free(music_path);
}

int	exit_game(t_game *game)
{
	stop_music();
	kill(game->pid + 1, SIGTERM);
	exit(0);
	return (0);
}
#else

void	music(t_game *game)
{
	char	*music_path;
	char	*full_path;

	music_path = file_render(game->music);
	if (music_path)
	{
		game->pid = -1;
		game->pid = fork();
		full_path = ft_strjoin(MUSIC, music_path);
		if (game->pid == 0)
		{
			system(full_path);
			kill(game->pid + 1, SIGTERM);
			exit(EXIT_FAILURE);
		}
		free(full_path);
	}
	if (music_path)
		free(music_path);
}

int	exit_game(t_game *game)
{
	kill(game->pid + 1, SIGTERM);
	exit(0);
	return (0);
}
#endif
