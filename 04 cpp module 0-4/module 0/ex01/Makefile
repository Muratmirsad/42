# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiraga <mdiraga@42istanbul.com.tr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 01:10:39 by mdiraga           #+#    #+#              #
#    Updated: 2023/08/22 01:11:36 by mdiraga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	@c++ $(FLAGS) main.cpp Contact.cpp Phonebook.cpp -o $(NAME)
	@clear
	@echo "program created."

clean:
	@rm -rf $(NAME)
	@echo "program cleaned."

fclean: clean

re: clean all