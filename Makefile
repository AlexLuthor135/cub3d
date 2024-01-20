SRCS		=	main.c map_render.c \
				image_render.c map_check.c utils.c \
				map_create.c raycast.c map_check_utils.c\
				file_render.c key_movement.c \
				key_rotation.c movement_math.c raycast_utils.c \

SRCS_BONUS		=	main.c map_render.c \
				image_render.c map_check.c utils.c \
				map_create.c utils2.c raycast.c mouse.c \
				file_render.c key_movement.c sprite_render.c\
				key_rotation.c minimap.c key_movement2.c \
				raycast_utils.c raycast_bonus.c sprite_utils.c \
				map_check_utils.c sky_bonus.c\

MLX_FLAGS		= 	-lmlx -framework OpenGL -framework AppKit
CC_FLAGS		=	-Wall -Wextra -Werror -g
CC				=	cc
SRCS_F			= src/
OBJS_F			= obj/

SCRS_FBONUS		= src_bonus/
OBJS_FBONUS		= obj_bonus/

LIBFT = inc/libft/
MLX = mlx/
GNL = inc/get_next_line/
HB = src_bonus/cub3d.h

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)
OBJS_P		=	$(addprefix $(OBJS_F), $(OBJS))
OBJS_PBONUS	=	$(addprefix $(OBJS_FBONUS), $(OBJS_BONUS))
NAME		= 	cub3D
NAME_BONUS	=	cub3D_bonus

all:$(NAME)

$(OBJS_F)%.o: $(SRCS_F)%.c Makefile cub3d.h
	@mkdir -p $(OBJS_F)
	@echo "Working on: $<"
	@$(CC) $(CC_FLAGS) -O3 -c $< -o $@

$(NAME): $(OBJS_P)
	@$(MAKE) -C $(MLX) 
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(GNL)
	@$(CC) $(CC_FLAGS) -O3 -L$(MLX) $(MLX_FLAGS) $(GNL)/get_next_line.a $(LIBFT)/libft.a -o $(NAME) $(OBJS_P)
	@echo "OK"

bonus: $(NAME_BONUS)

$(OBJS_FBONUS)%.o: $(SCRS_FBONUS)%.c Makefile cub3d_bonus.h
	@mkdir -p $(OBJS_FBONUS)
	@echo "Working on: $<"
	@$(CC) $(CC_FLAGS) -O3 -c $< -o $@

$(NAME_BONUS): $(OBJS_PBONUS)
	@$(MAKE) -C $(MLX) 
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(GNL)
	@$(CC) $(CC_FLAGS) -O3 -L$(MLX) $(MLX_FLAGS) $(GNL)/get_next_line.a $(LIBFT)/libft.a -o $(NAME_BONUS) $(OBJS_PBONUS)
	@echo "OK"

clean:
	@rm -rf $(OBJS_F)
	@rm -rf $(OBJS_FBONUS)
	@$(MAKE) clean -C $(MLX) 
	@$(MAKE) fclean -C $(LIBFT) 
	@$(MAKE) fclean -C $(GNL)

fclean:	clean
	@rm -rf $(NAME) $(NAME_BONUS)

re:		fclean all

.PHONY:	all clean fclean re
