# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 21:47:40 by mdiraga           #+#    #+#              #
#    Updated: 2023/12/20 22:07:09 by mdiraga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harl
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): main.cpp Harl.cpp
	@c++ $(FLAGS) main.cpp Harl.cpp -o $(NAME)
	@clear
	@echo "program created."

clean:
	@rm -rf $(NAME)
	@echo "program cleaned."

fclean: clean

re: clean all