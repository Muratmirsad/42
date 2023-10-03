NAME = cub3d
CFLAGS = -Wall -Werror -Wextra -I./minilibx -g
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx
MLX = ./minilibx/libmlx.a
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a
GET_NEXT_LINE = ./get_next_line/*.c
SRCS = src/*.c

all : $(MLX) $(NAME) $(LIBFT)

$(NAME): $(SRCS) $(MLX) $(LIBFT) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(PRINTF) $(LIBFT) $(GET_NEXT_LINE) -o $(NAME)

$(MLX):
	@make -C ./minilibx

$(LIBFT):
	@make -C ./libft
	@make -C ./ft_printf

clean:
	@make fclean -C ./libft
	@make fclean -C ./ft_printf
	@rm -rf *.dSYM

fclean: clean
	@rm -rf $(NAME)
	@make clean -C ./minilibx

re : fclean all

.PHONY: clean fclean re