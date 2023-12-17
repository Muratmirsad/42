SRCS	=	SRCS/GET_NEXT_LINE/get_next_line.c	SRCS/GET_NEXT_LINE/get_next_line_utils.c	\
		SRCS/cub3d.c SRCS/check_map.c SRCS/exits.c SRCS/get_info.c SRCS/utils_info.c SRCS/ft_split_special.c \
		SRCS/utils_check.c SRCS/keys.c SRCS/move.c SRCS/rotate.c SRCS/raycasting.c \
		SRCS/xpm_rgb_handle.c


LIBFT	=	SRCS/LIBFT/libft.a

MLX		=	./SRCS/mlx/libmlx.a

MLXF	=	-framework AppKit -framework OpenGL -L./SRCS/mlx -lmlx -I./SRCS/mlx -g

OBJS	=	$(SRCS:.c=.o)

NAME	=	cub3D

CC		=	gcc -Wall -Wextra -Werror

RM		=	rm -rf

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
				$(CC) $(MLXF) $(OBJS) $(MLX) $(LIBFT) -o $(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C ./SRCS/libft

$(LIBFT):
			make bonus -C ./SRCS/libft

$(MLX):
			make -C ./SRCS/mlx

fclean:
			$(RM) $(OBJS) $(NAME)
			make fclean -C ./SRCS/libft
			make clean -C ./SRCS/mlx

re:			fclean all

.PHONY:		all clean fclean re