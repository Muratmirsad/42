# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 11:20:36 by mdiraga           #+#    #+#              #
#    Updated: 2024/01/04 11:30:43 by mdiraga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp ClapTrap.cpp

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