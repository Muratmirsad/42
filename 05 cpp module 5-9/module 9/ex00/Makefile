NAME = btc
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp BitcoinExchange.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@c++ $(FLAGS) $(SRCS) -o $(NAME)
	@clear
	@echo "program created."

clean:
	@rm -rf $(NAME)
	@echo "program cleaned."

fclean: clean

re: clean all