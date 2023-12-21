# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 17:23:30 by mdiraga           #+#    #+#              #
#    Updated: 2023/12/21 17:23:31 by mdiraga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): main.cpp
	@c++ $(FLAGS) main.cpp -o $(NAME)
	@clear
	@echo "program created."

clean:
	@rm -rf $(NAME)
	@echo "program cleaned."

fclean: clean

re: clean all