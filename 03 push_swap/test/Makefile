NAME = push_swap

CC = -Wall -Wextra -Werror
SRC = src/ft_error.c \
      src/ft_papb.c \
      src/ft_rarbrr.c \
      src/ft_rrarrbrrr.c \
      src/ft_sasbss.c \
      src/push_swap.c \
      src/read_arg.c \
      src/convert_to_smaller.c \
      src/sorting_big_stack.c \
      src/sorting_bubble.c \
      src/sorting_small_stack.c \
      src/sorting_utils.c \
      src/sorting.c

OUTS = $(SRC:%.c=%.o)
RUNOUTS = out/*
LIBS = libft/libft.a

all: $(LIBS) $(OUT) $(RUN)

$(LIBS):
	@make -C libft

$(OUT):
	@mkdir -p out
	@gcc $(CC) $(SRC) -c
	@mv *.o out/

$(RUN): $(OUT)
	@gcc $(CC) $(RUNOUTS) $(LIBS) -o $(NAME)

clean:
	@make clean -C libft
	@rm -rf out

fclean:
	@make fclean -C libft
	@rm -rf out
	@rm -f $(NAME)

re: fclean all
