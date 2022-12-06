NAME		=	libftprintf.a

SRCS		=	ft_printf.c \
				ft_putnbr.c \
				ft_putunsigned.c \
				ft_putstr.c \
				ft_putchar.c \
				ft_puthexadecimal.c \
				ft_putpointer.c \
				ft_strdup.c \
				ft_strlen.c

BNS_SRCS	=

				
OBJS		=	$(SRCS:%.c=%.o)

BNS_OBJS	=	$(BNS_SRCS:%.c=%.o)

FLAGS		=	-Wall -Werror -Wextra

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

bonus: $(NAME)
	gcc $(FLAGS) -c $(BNS_SRCS) -I ./
	ar rc $(NAME) $(BNS_OBJS)

clean:
	rm -f $(OBJS) $(BNS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
