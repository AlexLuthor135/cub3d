/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:55:29 by alappas           #+#    #+#             */
/*   Updated: 2024/05/15 21:58:24 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WINDOW_H		800
# define WINDOW_W		1024


# define MOVE_SPEED	0.02
# define ROTATION_SPEED 0.02
# define M_PI		3.14159265358979323846

# if defined(__APPLE__)
#  include "mlx_mac/mlx.h"
#  define KEY_W		13
#  define KEY_A		0
#  define KEY_S		1
#  define KEY_D		2
#  define KEY_ESC	53
#  define KEY_LEFT	123
#  define KEY_RIGHT	124
# elif defined(__linux__)
#  include "mlx_linux/mlx.h"
#  define KEY_W   'w'
#  define KEY_A   'a'
#  define KEY_S   's'
#  define KEY_D   'd'
#  define KEY_ESC 65307
#  define KEY_LEFT	65361
#  define KEY_RIGHT	65363
#  include <X11/keysym.h>
# endif
# include "inc/libft/libft.h"
# include <stdlib.h>
# include <math.h>

typedef struct s_raycast
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	dir_x;
	double	dir_y;
	double	view_x;
	double	view_y;
	int		map_x;
	int		map_y;
	double	ddx;
	double	ddy;
	double	step_x;
	double	step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		hit;
	int		side;
	double	wall_dist;
	double	texture_pos;
	double	texture_step;
	double	texture_y;
	double	texture_x;
	int		color;
	int		wall_type;
	int		draw_start;
	int		draw_end;
	int		line_h;
}				t_raycast;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}				t_img;

typedef struct s_wall
{
	t_img	*img;
	int		width;
	int		height;
}				t_wall;

typedef struct s_index
{
	int	north;
	int	south;
	int	west;
	int	east;
	int	floor;
	int	ceiling;
}				t_index;

typedef struct s_game
{
	int				map_height;
	int				map_length;
	double			player_pos_x;
	double			player_pos_y;
	char			**map_data;
	void			*mlx;
	void			*win;
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*floor;
	char			*ceiling;
	char			direction;
	unsigned int	floor_bit;
	unsigned int	ceiling_bit;
	char			**map;
	char			*l_el;
	int				player_index;
	int				x;
	int				y;
	int				key_w;
	int				key_s;
	int				key_d;
	int				key_a;
	int				key_esc;
	int				key_right;
	int				key_left;
	t_raycast		*raycast;
	t_img			img;
	t_index			s_index;
	t_wall			wall[4];
}	t_game;

//file_render.c
void			image_paste(t_game *game, char *path, int i);
char			*file_render(char *path);

//image_render.c
void			ceiling_floor(t_game *game);
unsigned int	color_handle(char	*color_string);
int				main_draw(t_game *game);

//key_movement.c
int				key_press(int key, t_game *game);
int				key_release(int key, t_game *game);
int				keys_execute(t_game *game);
int				key_movement(int key, t_game *game);

//key_rotation.c
void			rotate_left(t_game *game, double old_direction_x,
					double old_plane_x);
void			rotate_right(t_game *game, double old_direction_x,
					double old_plane_x);
void			rotate_camera(t_game *game, int key);

//main.c
int				check_ext(char *argv);
int				exit_game(t_game *game);

//map_check_utils.c
int				check_char(char map, int i);
void			init_player(t_game *game, int x, int y);
int				error_walls_helper(t_game *game, size_t x, int y);
void			last_element(t_game *game);
int				error_string_helper(char **map, int i);

//map_check_utils2.c
void			index_string_error(t_game *game);
void			index_string_helper(t_game *game, int i);

//map_check.c
int				error_string(t_game *game);
int				map_check(t_game *game);

//map_create.c
char			**map_create(t_game *game);

//map_render.c
void			map_alloc(t_game *game);
char			*sprite_alloc(t_game *game, char *str, int len);
void			map_render(t_game *game, char *map);

//math_movement.c
void			front_move(t_game *game);
void			back_move(t_game *game);
void			left_move(t_game *game);
void			right_move(t_game *game);

//raycast_utils.c
void			walltype_detection(t_raycast *rc);
void			step_determination(t_game *game, t_raycast *rc);
void			wallhit_detection(t_game *game, t_raycast *rc);
void			raydir_calculation(t_game *game, t_raycast *rc, int x);
void			draw_calculation(t_raycast *rc);

//raycast.c
void			ft_raycast(t_game *game, t_raycast *rc);

//utils.c
void			ft_strdel(char **s);
void			free_2darray(char **array);
void			put_pixel(t_img *img, int x, int y, int color);
unsigned int	get_pixel(t_img *img, int x, int y);
void			init_facing_direction(t_game *game);

#endif