# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 16:27:08 by mdiraga           #+#    #+#              #
#    Updated: 2023/08/20 16:40:00 by mdiraga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	@c++ $(FLAGS) megaphone.cpp -o $(NAME)
	@clear
	@echo "program created."

clean:
	@rm -rf $(NAME)
	@echo "program cleaned."

fclean: clean

re: clean all