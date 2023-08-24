NAME = push_swap

SRCS = src/convert.c \
		src/ft_error.c \
		src/ft_papb.c \
		src/ft_rarbrr.c \
		src/ft_rrarrbrrr.c \
		src/ft_sasbss.c \
		src/push_swap.c \
		src/read_arg.c \
		src/sorting_big_stack.c \
		src/sorting_bubble.c \
		src/sorting_small_stack.c \
		src/sorting_utils.c \
		src/sorting.c \
		src/push_back.c

LIBFT = libft/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCS)
	@clear
	@echo "\033[33m\n\tCompiling...\n\033[0m"
	@make -C ./libft
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@clear
	@echo "\033[32m\n\tOK!\033\n"
	@ls -l push_swap

clean:
	@make fclean -C ./libft
	@clear
	@echo "\033[32m\n\tLibft files cleared.\033\n"

fclean: clean
	@rm -rf $(NAME)
	@clear
	@ls -la
	@echo "\033[32m\n\tProgram cleared.\033\n"

re: fclean all

.PHONY: all fclean clean re