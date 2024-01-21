# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 20:44:21 by mdiraga           #+#    #+#              #
#    Updated: 2024/01/20 20:44:22 by mdiraga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp

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