NAME = philo
CFLAGS = -Wall -Werror -Wextra -fsanitize=thread -g
SRCS = philo.c utils.c one_philo.c ft_atoi.c

all : $(NAME)

$(NAME): $(SRCS)
	@echo compiling...
	@gcc $(CFLAGS) $(SRCS) -o $(NAME)
	@clear
	@echo " ---> philo <---"
	@echo program created.

clean:
	@rm -rf *.dSYM

fclean: clean
	@rm -rf $(NAME)
	@echo program deleted.

re: fclean all

.PHONY: clean fclean re