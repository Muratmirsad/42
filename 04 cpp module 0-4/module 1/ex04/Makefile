# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 18:11:17 by mdiraga           #+#    #+#              #
#    Updated: 2023/12/20 22:04:28 by mdiraga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): main.cpp replace.cpp
	@c++ $(FLAGS) main.cpp replace.cpp -o $(NAME)
	@clear
	@echo "program created."

clean:
	@rm -rf $(NAME)
	@echo "program cleaned."

fclean: clean

re: clean all