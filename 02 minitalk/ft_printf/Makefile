NAME		=	libftprintf.a

SRCS		=	ft_printf.c \
				ft_putnbr.c \
				ft_putunsigned.c \
				ft_putstr.c \
				ft_putchar.c \
				ft_puthexadecimal.c \
				ft_putpointer.c

				
OBJS		=	$(SRCS:%.c=%.o)

FLAGS		=	-Wall -Werror -Wextra

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
