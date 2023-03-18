NAME=so_long
CFLAGS = -Wall -Werror -Wextra -I./minilibx -g
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx
MLX = ./minilibx/libmlx.a
LIBFT =	./ft_printf/libftprintf.a
GET_NEXT_LINE = ./get_next_line/*.c
SRCS = src/*.c

all : $(MLX) $(NAME)

$(NAME): $(SRCS) $(MLX) $(LIBFT) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(LIBFT) $(GET_NEXT_LINE) -o $(NAME)

$(MLX):
	@make -C ./minilibx

$(LIBFT):
	@make bonus -C ./ft_printf


clean:

fclean: clean
	@rm -rf $(NAME)
	@make clean -C ./minilibx
	@make fclean -C ./ft_printf

re : fclean all

.PHONY: clean fclean re