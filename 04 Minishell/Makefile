SRCS		=		minishell.c lst_func.c parser.c utils.c  cmd_built.c ft_echo.c ft_exit.c \
					pwd_env.c ft_export.c execve.c ft_cd.c

LIBFT		=		-I./libft

OBJS		=		$(SRCS:.c=.o)

NAME		=		minishell

CC			=		gcc

CFLAGS		=		

RM			=		rm -rf

all:		$(NAME) $(LIBFT)

$(LIBFT):
			make bonus -C ./libft

$(NAME):	$(OBJS) $(LIBFT)
				$(CC) $(CFLAGS) -lreadline $(OBJS) libft/libft.a  -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)
			make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re