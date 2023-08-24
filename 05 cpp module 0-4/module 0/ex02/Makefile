NAME = bank
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	@c++ $(FLAGS) tests.cpp Account.cpp -o $(NAME)
	@clear
	@echo "program created."

clean:
	@rm -rf $(NAME)
	@echo "program cleaned."

fclean: clean

re: clean all