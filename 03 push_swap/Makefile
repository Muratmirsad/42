NAME = push_swap

SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
LIBFTOBJS = libft/*.o
FTPRINTFOBJS = ft_printf/*.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB= libft/libft.a
PRINT= ft_printf/libftprintf.a

INC_FT = libft
INC_FT_PRINTF = ft_printf

all: $(LIB) $(PRINT) $(NAME)

$(LIB):
	@make -C libft

$(PRINT):
	@make -C ft_printf

$(NAME): ${OBJS}
	@$(CC) $(OBJS) -o $(NAME) $(LIB) $(PRINT)

.c.o:
	@$(CC) $(CFLAGS) -I $(INC_FT) -I $(INC_FT_PRINTF) -c $< -o $@

clean:
	@rm $(OBJS)
	@rm $(LIBFTOBJS)
	@rm $(FTPRINTFOBJS)

fclean: clean
	@rm $(NAME)
	@rm $(LIBFTOBJS) libft/libft.a
	@rm $(FTPRINTFOBJS) ft_printf/libftprintf.a

ffclean: fclean
	@make fclean -C libft
	@make fclean -C ft_printf

re: fclean all

.PHONY: all re clean fclean ffclean