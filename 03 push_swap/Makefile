NAME = push_swap

CC = -Wall -Wextra -Werror
SRC = src/ft_error.c \
		src/ft_papb.c \
		src/ft_rarbrr.c \
		src/ft_rrarrbrrr.c \
		src/ft_sasbss.c \
		src/push_swap.c \
		src/read_arg.c \
		src/sorting_1.c

OUTS = $(SRC:%.c=%.o)
RUNOUTS = out/*
LIBS = libft/libft.a \
		ft_printf/libftprintf.a

all: $(LIB) $(OUT) $(RUN)

$(LIB):
	@make -C libft
	@make -C ft_printf

$(OUT):
	@gcc $(CC) $(SRC) -c $(OUTS)
	@mv *.o out/

$(RUN):
	@gcc $(CC) $(RUNOUTS) $(LIBS) -o $(NAME)

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@rm out/*.o

fclean:
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm out/*
