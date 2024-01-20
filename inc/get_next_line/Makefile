SRCS			=	get_next_line.c get_next_line_utils.c get_next_line_bonus.c\
					get_next_line_utils_bonus.c ft_listlast.c\


OBJS	=	${SRCS:.c=.o}

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= get_next_line.a

MAKEFLAGS		+= -silent

all:			$(NAME)

$(NAME):  $(OBJS)
				ar rcs $@ $^

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re