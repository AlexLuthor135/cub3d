/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:55:29 by alappas           #+#    #+#             */
/*   Updated: 2024/01/20 22:21:21 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# define WINDOW_H		800
# define WINDOW_W		1024

# define LEFT_KEY	123
# define RIGHT_KEY	124

# define MOVE_SPEED	0.06
# define ROTATION_SPEED 0.04
# define M_PI		3.14159265358979323846

//To change the size of sprites
# define UDIV 2.0
# define VDIV 2.0
# define VMOVE 200.0

# include "mlx/mlx.h"
# include "inc/libft/libft.h"
# include "inc/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <math.h>
# include <signal.h>

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
	float	raydir_x0;
	float	raydir_y0;
	float	raydir_x1;
	float	raydir_y1;
	float	floorstep_x;
	float	floorstep_y;
	float	floor_x;
	float	floor_y;
	int		cell_x;
	int		cell_y;
	float	pos_z;
	float	row_distance;
	float	cf_height;
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;
	double	v_movescreen;
	double	sprite_height;
	double	drawstart_y;
	double	drawend_y;
	double	sprite_width;
	double	drawstart_x;
	double	drawend_x;
	double	tex_x;
	double	tex_y;
	double	sky_offset_y;
	double	sky_orientation;
	double	sky_ratio_x;
	double	sky_ratio_y;
	double	sky_coord_x;
	double	sky_coord_y;
	double	sky_horizon;
	int		door_i;
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

typedef struct s_sprite
{
	double	*x;
	double	*y;
	double	*dist;
}				t_sprite;

typedef struct s_game
{
	int				map_height;
	int				map_length;
	double			player_pos_x;
	double			player_pos_y;
	pid_t			pid;
	char			**map_data;
	void			*mlx;
	void			*win;
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*floor;
	char			*ceiling;
	char			*barrel;
	char			*music;
	char			*door;
	char			direction;
	unsigned int	floor_bit;
	unsigned int	ceiling_bit;
	char			**map;
	int				player_index;
	int				sprite_index;
	int				door_index;
	int				x;
	int				y;
	double			zbuf[WINDOW_W];
	int				key_w;
	int				key_s;
	int				key_d;
	int				key_a;
	int				key_e;
	int				key_esc;
	int				key_right;
	int				key_left;
	t_img			c_f;
	t_raycast		*raycast;
	t_sprite		*sprite;
	t_img			img;
	t_wall			wall[8];
}	t_game;

//file_render.c
void			image_paste(t_game *game, char *path, int i);
char			*file_render(char *path);

//image_render.c
void			ceiling_floor(t_game *game);
unsigned int	color_handle(char	*color_string);
int				main_draw(t_game *game);

//key_movement.c
void			front_move(t_game *game);
void			back_move(t_game *game);
void			left_move(t_game *game);
void			right_move(t_game *game);

//key_movement2.c
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
int				sprite_check(t_game *game);
int				error_string_helper(char **map, int i);

//map_check.c
int				error_string(t_game *game);
int				map_check(t_game *game);

//map_create.c
char			**map_create(t_game *game);

//map_render.c
void			map_alloc(t_game *game);
char			*sprite_alloc(t_game *game, char *str, int len);
char			**map_render(t_game *game, char *map);

//minimap.c
void			draw_screen(t_game *game);
void			draw_void(t_game *game);
void			draw_hero(t_game *game);

//mouse.c
int				ft_mouse(t_game *game);
void			ft_direction(t_raycast *pl, double rotate);
void			ft_view(t_raycast *pl, double rotate);
void			ft_params(t_game *game, double rotare);

//raycast_bonus.c
void			bonus_c_f(t_game *game, t_raycast *rc);

//raycast_utils.c
void			walltype_detection(t_raycast *rc);
void			step_determination(t_game *game, t_raycast *rc);
void			wallhit_detection(t_game *game, t_raycast *rc);
void			raydir_calculation(t_game *game, t_raycast *rc, int x);
void			draw_calculation(t_raycast *rc);

//raycast.c
void			rayhit_assist(t_game *game, t_raycast *rc);
void			ft_raycast(t_game *game, t_raycast *rc);

//sky_bonus
void			draw_sky(t_game *game);

//sprite_render.c
void			sprite_locate(t_game *game);
void			sprite_render(t_game *game, t_raycast *rc);

//sprite_utils.c
void			text_x_calc(t_game *game, t_raycast *rc, int stripe);
void			sprite_dist_calc(t_game *game);

//utils.c
void			ft_strdel(char **s);
void			free_2darray(char **array);
void			put_pixel(t_img *img, int x, int y, int color);
unsigned int	get_pixel(t_img *img, int x, int y);

//utils2.c
void			music(t_game *game);
void			mlx_skip(t_game *game);
void			init_facing_direction(t_game *game);
void			init_sprite(t_game *game);
void			sprite_parse(t_game *game);

#endif
